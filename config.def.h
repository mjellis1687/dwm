/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"
#define BROWSER "brave"

#define SESSION_FILE "/tmp/dwm-session"

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int showtitle          = 1;        /* 0 means no title */
static const int showtags           = 1;        /* 0 means no tags */
static const int showlayout         = 0;        /* 0 means no layout indicator */
static const int showstatus         = 1;        /* 0 means no status bar */
static const int showfloating       = 1;        /* 0 means no floating indicator */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=13", "NotoColorEmoji:pixelsize=10:antialias=true:autohint=true" };
static const char dmenufont[]       = "monospace:size=13";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
	[SchemeStatus]  = { col_gray3, col_gray1,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]  = { col_gray4, col_cyan,  "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
	[SchemeTagsNorm]  = { col_gray3, col_gray1,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
	[SchemeInfoSel]  = { col_gray4, col_cyan,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
	[SchemeInfoNorm]  = { col_gray3, col_gray1,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ TERMCLASS,  NULL,       NULL,       0,            0,           -1 },
	{ "Nautilus", NULL,       NULL,       1 << 8,		0,			  2 },
	{ "Slack",	  NULL,		  NULL,		  1 << 1,		0,			  1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 120;  /* refresh rate (per second) for client move/resize */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	/* modifier                     key				function			argument */
	{ MODKEY,						XK_grave,		spawn,				{.v = (const char*[]){ "dmenuunicode", NULL } } },
	TAGKEYS(                        XK_1,      		                	0)
	TAGKEYS(                        XK_2,      		                	1)
	TAGKEYS(                        XK_3,      		                	2)
	TAGKEYS(                        XK_4,      		                	3)
	TAGKEYS(                        XK_5,      		                	4)
	TAGKEYS(                        XK_6,      		                	5)
	TAGKEYS(                        XK_7,      		                	6)
	TAGKEYS(                        XK_8,      		                	7)
	TAGKEYS(                        XK_9,      		                	8)
	{ MODKEY,                       XK_0,      		view,           	{.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      		tag,            	{.ui = ~0 } },
	{ MODKEY,						XK_minus,		spawn,				SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,				XK_minus,		spawn,				SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%-; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,						XK_equal,		spawn,				SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,				XK_equal,		spawn,				SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%+; kill -44 $(pidof dwmblocks)") },
	/* { MODKEY,					XK_BackSpace,	NULL,				NULL }, */
	/* { MODKEY|ShiftMask,			XK_BackSpace,	NULL,				NULL }, */
	{ MODKEY,					    XK_a,      		togglebartitle, 	{0} },
	{ MODKEY|ShiftMask,             XK_a,      		togglebartags,  	{0} },
	{ MODKEY,                       XK_b,      		togglebar,      	{0} },
	{ MODKEY|ShiftMask,				XK_b,      		togglebarfloat, 	{0} },
	/* { MODKEY,					XK_c,			NULL,				NULL }, */
	/* { MODKEY|ShiftMask,			XK_c,			NULL,				NULL }, */
	{ MODKEY,						XK_d,			spawn,				{.v = (const char*[]){ "dmenu_run", NULL } } },
	{ MODKEY|ShiftMask,				XK_d,			spawn,				{.v = (const char*[]){ "passmenu", NULL } } },
	/* { MODKEY,					XK_e,			NULL,				NULL }, */
	/* { MODKEY|ShiftMask,			XK_e,			NULL,				NULL }, */
	{ MODKEY,						XK_f,			togglefullscr,		{0} },
	{ MODKEY|ShiftMask,				XK_f,			setlayout,			{.v = &layouts[1]} },
	/* { MODKEY,					XK_g,			NULL,				NULL }, */
	/* { MODKEY|ShiftMask,			XK_g,			NULL,				NULL }, */
	{ MODKEY,                       XK_h,      		setmfact,       	{.f = -0.05} },
	{ MODKEY|ShiftMask,				XK_h,			tagmon,				{.i = -1 } },
	/* { MODKEY,					XK_i,			NULL,				NULL }, */
	/* { MODKEY|ShiftMask,			XK_i,			NULL,				NULL }, */
	{ MODKEY,						XK_j,      		focusstack,     	{.i = +1 } },
	/* { MODKEY|ShiftMask,			XK_j,			NULL,				NULL }, */
	{ MODKEY,                       XK_k,      		focusstack,     	{.i = -1 } },
	/* { MODKEY|ShiftMask,			XK_k,			NULL,				NULL }, */
	{ MODKEY,                       XK_l,      		setmfact,       	{.f = +0.05} },
	{ MODKEY|ShiftMask,				XK_l,			tagmon,				{.i = +1 } },
	{ MODKEY,                       XK_m,      		setlayout,      	{.v = &layouts[2]} },
	{ MODKEY|ShiftMask,				XK_m,			spawn,				SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)") },
	/* { MODKEY,					XK_n,			NULL,				NULL }, */
	/* { MODKEY|ShiftMask,			XK_n,			NULL,				NULL }, */
	{ MODKEY,						XK_o,			incnmaster,			{.i = +1 } },
	{ MODKEY|ShiftMask,				XK_o,			incnmaster, 		{.i = -1 } },
	/* { MODKEY,                    XK_p,      		spawn,          	{.v = dmenucmd } }, */
	/* { MODKEY,					XK_p,			NULL,				NULL }, */
	/* { MODKEY|ShiftMask,			XK_p,			NULL,				NULL }, */
	{ MODKEY,						XK_q,			killclient,			{0} },
	/* { MODKEY|ShiftMask,          XK_q,      		quit,           	{0} }, */
	/* { MODKEY|ShiftMask,			XK_q,			spawn,				{.v = (const char*[]){ "sysact", NULL } } }, */
	{ MODKEY|ControlMask,			XK_q,			quit,				{0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,			quit,				{1} },
	{ MODKEY,						XK_r,			spawn,				{.v = (const char*[]){ "nautilus", NULL } } },
	{ MODKEY|ShiftMask,				XK_r,			spawn,				{.v = (const char*[]){ TERMINAL, "-e", "htop", NULL } } },
	{ MODKEY,                       XK_s,      		togglebarstatus,	{0} },
	{ MODKEY|ShiftMask,				XK_s,      		togglebarlt,    	{0} },
	{ MODKEY,                       XK_t,      		setlayout,      	{.v = &layouts[0]} },
	/* { MODKEY|ShiftMask,			XK_t,			NULL,				NULL }, */
	/* { MODKEY,					XK_u,			NULL,				NULL }, */
	/* { MODKEY|ShiftMask,			XK_u,			NULL,				NULL }, */
	/* { MODKEY,					XK_v,			NULL,				NULL }, */
	/* { MODKEY|ShiftMask,			XK_v,			NULL,				NULL }, */
	{ MODKEY,						XK_w,			spawn,				{.v = (const char*[]){ BROWSER, NULL } } },
	/* { MODKEY|ShiftMask,			XK_w,			NULL,				NULL }, */
	/* { MODKEY,					XK_x,			NULL,				NULL }, */
	/* { MODKEY|ShiftMask,			XK_x,			NULL,				NULL }, */
	/* { MODKEY,					XK_y,			NULL,				NULL }, */
	/* { MODKEY|ShiftMask,			XK_y,			NULL,				NULL }, */
	/* { MODKEY,					XK_z,			NULL,				NULL }, */
	/* { MODKEY|ShiftMask,			XK_z,			NULL,				NULL }, */
	/* Other keys on main keyboard */
	{ MODKEY,                       XK_Tab,    		view,           	{0} },
	/* { MODKEY,					XK_bracketleft,	spawn,				{.v = (const char*[]){ "mpc", "seek", "-10", NULL } } }, */
	/* { MODKEY|ShiftMask,			XK_bracketleft,	spawn,				{.v = (const char*[]){ "mpc", "seek", "-60", NULL } } }, */
	/* { MODKEY,					XK_bracketright,spawn,				{.v = (const char*[]){ "mpc", "seek", "+10", NULL } } }, */
	/* { MODKEY|ShiftMask,			XK_bracketright,spawn,				{.v = (const char*[]){ "mpc", "seek", "+60", NULL } } }, */
	{ MODKEY,						XK_backslash,	view,				{0} },
	/* { MODKEY,					XK_semicolon,	NULL,				NULL }, */
	/* { MODKEY|ShiftMask,			XK_semicolon,	NULL,				NULL }, */
	/* { MODKEY,					XK_apostrophe,	togglescratch,		{.ui = 1} }, */
	/* { MODKEY|ShiftMask,			XK_apostrophe,	NULL,				NULL }, */
	{ MODKEY,						XK_Return, 		spawn,          	{.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Return, 		zoom,           	{0} },
	{ MODKEY|ShiftMask,             XK_comma,  		tagmon,         	{.i = -1 } },
	{ MODKEY,                       XK_comma,  		focusmon,       	{.i = -1 } },
	{ MODKEY,                       XK_period, 		focusmon,       	{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_period, 		tagmon,         	{.i = +1 } },
	{ MODKEY,                       XK_space,  		setlayout,      	{0} },
	{ MODKEY|ShiftMask,             XK_space,  		togglefloating, 	{0} },
	/* Arrow keys */
	{ MODKEY,						XK_Left,		focusmon,			{.i = -1 } },
	{ MODKEY|ShiftMask,				XK_Left,		tagmon,				{.i = -1 } },
	{ MODKEY,						XK_Right,		focusmon,			{.i = +1 } },
	{ MODKEY|ShiftMask,				XK_Right,		tagmon,				{.i = +1 } },
	/* { MODKEY,					XK_Insert,		spawn,				SHCMD("xdotool type $(grep -v '^#' ~/.local/share/larbs/snippets | dmenu -i -l 50 | cut -d' ' -f1)") }, */
	/* { MODKEY,					XK_Home,		NULL,				NULL }, */
	/* { MODKEY,					XK_Page_Up,		shiftview,			{ .i = -1 } }, */
	/* { MODKEY|ShiftMask,			XK_Page_Up,		shifttag,			{ .i = -1 } }, */
	{ MODKEY,						XK_Delete,		spawn,				{.v = (const char*[]){ "dmenurecord", "kill", NULL } } },
	/* { MODKEY,					XK_End,			NULL,				NULL }, */
	/* { MODKEY,					XK_Page_Down,	shiftview,			{ .i = +1 } }, */
	/* { MODKEY|ShiftMask,			XK_Page_Down,	shifttag,			{ .i = +1 } }, */
	{ 0,							XK_Print,		spawn,				SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },
	{ ShiftMask,					XK_Print,		spawn,				{.v = (const char*[]){ "maimpick", NULL } } },
	{ MODKEY,						XK_Print,		spawn,				{.v = (const char*[]){ "dmenurecord", NULL } } },
	{ MODKEY|ShiftMask,				XK_Print,		spawn,				{.v = (const char*[]){ "dmenurecord", "kill", NULL } } },
	/* { MODKEY,					XK_Scroll_Lock,	spawn,				SHCMD("killall screenkey || screenkey &") }, */
	{ MODKEY,						XK_F1,			spawn,				SHCMD("groff -mom /usr/local/share/dwm/larbs.mom -Tpdf | zathura -") },
	{ MODKEY,						XK_F2,			spawn,				{.v = (const char*[]){ "tutorialvids", NULL } } },
	{ MODKEY,						XK_F3,			spawn,				{.v = (const char*[]){ "displayselect", NULL } } },
	{ MODKEY,						XK_F4,			spawn,				SHCMD(TERMINAL " -e pulsemixer; kill -44 $(pidof dwmblocks)") },
	/* { MODKEY,					XK_F5,			xrdb,				{.v = NULL } }, */
	/* { MODKEY,					XK_F6,			spawn,				{.v = (const char*[]){ "torwrap", NULL } } }, */
	/* { MODKEY,					XK_F7,			spawn,				{.v = (const char*[]){ "td-toggle", NULL } } }, */
	/* { MODKEY,					XK_F8,			spawn,				{.v = (const char*[]){ "mailsync", NULL } } }, */
	{ MODKEY,						XK_F9,			spawn,				{.v = (const char*[]){ "mounter", NULL } } },
	{ MODKEY,						XK_F10,			spawn,				{.v = (const char*[]){ "unmounter", NULL } } },
	/* { MODKEY,					XK_F11,			spawn,				SHCMD("mpv --untimed --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") }, */
	/* { MODKEY,					XK_F12,			spawn,				SHCMD("remaps") }, */
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
