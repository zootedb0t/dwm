/* See LICENSE file for copyright and license details. */

/* some macros */
#define ICONSIZE 20   /* icon size */
#define ICONSPACING 5 /* space between icon and title */
#define OPAQUE 0xffU /* 255 in hexadecimal */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 10;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 15;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 15;       /* vert inner gap between windows */
static const unsigned int gappoh    = 15;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 15;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char buttonbar[]       = " ";
static const bool viewontag         = true;     /* Switch view on tag switch */
static const int titlehighlight     = 0;        /* 0 means no highlight on window title */
static const int horizpadbar        = 8;        /* horizontal padding for statusbar */
static const int vertpadbar         = 8;        /* vertical padding for statusbar */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;   /* 0 means no systray */
static const char *fonts[]          = { "JetBrains Mono:pixelsize=20:antialias=true:autohint=true",
                                        "JoyPixels:pixelsize=20:antialias=true:autohint=true",
                                      };
static const char dmenufont[]       = "monospace:size=10";

/* bar opacity from 0 to 255 (Solid) */
static const unsigned int baralpha = 180;
static const unsigned int borderalpha = OPAQUE;

static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char btnbgcolor[]            = "#222222";
static char btnfgcolor[]            = "#bbbbbb";
static char titlebgcolor[]          = "#222222";
static char titlefgcolor[]          = "#bbbbbb";

static char *colors[][3] = {
	  /*               fg             bg             border   */
	  [SchemeNorm] = { normfgcolor,   normbgcolor,   normbordercolor },
	  [SchemeSel] =  { selfgcolor,    selbgcolor,    selbordercolor  },
	  [SchemeBtn] =  { btnfgcolor,    btnbgcolor,    normbordercolor },
	  [TitleText] =  { titlefgcolor,  titlebgcolor,  normbordercolor },
};

static const unsigned int alphas[][3]      = {
	  /*               fg      bg        border     */
	  [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	  [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
	  [SchemeBtn]  = { OPAQUE, baralpha, borderalpha },
	  [TitleText]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                  instance          title                         tags mask           iscentered        isfloating          isterminal          noswallow           monitor */
	{ "Gimp",                 NULL,             NULL,                         0,                  0,                1,                  0,                  0,                  -1 },
	// { "firefox",              NULL,             NULL,                         1 << 8,             0,                0,                  0,                  -1,                 -1 },
	{ "firefox",              "Browser",        "About Mozilla Firefox",      0,                  1,                1,                  0,                  0,                  -1 },
	{ "firefox",              "Toolkit",        "Picture-in-Picture",         0,                  1,                1,                  0,                  0,                  -1 },
	{ "firefox-nightly",      "Browser",        NULL,                         0,                  1,                1,                  0,                  0,                  -1 },
	{ "firefox-nightly",      "Toolkit",        "Picture-in-Picture",         0,                  1,                1,                  0,                  0,                  -1 },
	{ "thunderbird",          "Mail",           "About Mozilla Thunderbird",  0,                  1,                1,                  0,                  0,                  -1 },
	{ "mpv",                  "newsboat",       NULL,                         0,                  0,                1,                  0,                  0,                  -1 },
	{ "Deno",                 "deno",           "Peek preview",               0,                  0,                0,                  0,                  1,                  -1 },
	{ "Protonvpn",            "protonvpn",      "Proton VPN",                 0,                  0,                1,                  0,                  1,                  -1 },
	{ "Galculator",           "galculator",     "galculator",                 0,                  1,                1,                  0,                  1,                  -1 },
	{ "Pavucontrol",          "pavucontrol",    "Volume Control",             0,                  1,                1,                  0,                  1,                  -1 },
	{ "Spotify",              "spotify",        NULL,                         0,                  0,                0,                  0,                  0,                  -1 },
	// Change class name to whatever termianl you use. For window to swallowing to work
	{ "St",                   NULL,             NULL,                         0,                  0,                0,                  1,                  0,                  -1 },
	{ NULL,                   NULL,             "Event Tester",               0,                  0,                0,                  0,                  1,                  -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "shiftview.c"
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol   arrange function */
	/* first entry is default */
	{ "󰽙",      tile },
	{ "󰍉",      monocle },
	{ "󱍸",      spiral },
	{ "󰪏",      dwindle },
	{ "󰘸",      deck },
	{ "󱕕",      bstack },
	{ "󰝘",      horizgrid },
	{ "󱗼",      gaplessgrid },
	{ "󱒅",      centeredmaster },
	{ "󱒆",      centeredfloatingmaster },
	{ "",      NULL },    /* no layout function means floating behavior */
	{ NULL,     NULL },
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
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };
static const char *layoutmenu_cmd = "layoutmenu.sh";
static const char *menu_cmd[]    = { "menu.sh", NULL }; /* desktop right-click menu */

static const Key keys[] = {
	/* modifier                           key                 function              argument */
	{ MODKEY,                             XK_p,               spawn,                {.v = dmenucmd } },
	{ MODKEY | ShiftMask,                 XK_Return,          spawn,                {.v = termcmd } },
	{ MODKEY | ShiftMask,                 XK_s,               togglescratch,        {.v = scratchpadcmd } },
	{ MODKEY,                             XK_b,               togglebar,            {0} },
	{ MODKEY,                             XK_j,               focusstack,           {.i = +1 } },
	{ MODKEY,                             XK_k,               focusstack,           {.i = -1 } },
	{ MODKEY | ShiftMask,                 XK_j,               inplacerotate,        {.i = +1} },
	{ MODKEY | ShiftMask,                 XK_k,               inplacerotate,        {.i = -1} },
	{ MODKEY | ShiftMask,                 XK_h,               inplacerotate,        {.i = +2} },
	{ MODKEY | ShiftMask,                 XK_l,               inplacerotate,        {.i = -2} },
	{ MODKEY,                             XK_i,               incnmaster,           {.i = +1 } },
	{ MODKEY,                             XK_d,               incnmaster,           {.i = -1 } },
	{ MODKEY,                             XK_h,               setmfact,             {.f = -0.05} },
	{ MODKEY,                             XK_l,               setmfact,             {.f = +0.05} },
	{ MODKEY,                             XK_backslash,       setcfact,             {.f = +0.25} },
	{ MODKEY | ShiftMask,                 XK_backslash,       setcfact,             {.f = -0.25} },
	{ MODKEY,                             XK_o,               reset_mfact,          {0} },
	{ MODKEY | ShiftMask,                 XK_o,               setcfact,             {.f =  0.00} },
	{ MODKEY,                             XK_Return,          zoom,                 {0} },
	{ MODKEY | ControlMask,               XK_u,               incrgaps,             {.i = +1 } },
	{ MODKEY | ControlMask | ShiftMask,   XK_u,               incrgaps,             {.i = -1 } },
	{ MODKEY | ControlMask,               XK_i,               incrigaps,            {.i = +1 } },
	{ MODKEY | ControlMask | ShiftMask,   XK_i,               incrigaps,            {.i = -1 } },
	{ MODKEY | ControlMask,               XK_o,               incrogaps,            {.i = +1 } },
	{ MODKEY | ControlMask | ShiftMask,   XK_o,               incrogaps,            {.i = -1 } },
	{ MODKEY | ControlMask,               XK_0,               togglegaps,           {0} },
	{ MODKEY | ControlMask | ShiftMask,   XK_0,               defaultgaps,          {0} },
	{ MODKEY,			                        XK_bracketleft,	    shiftview,            { .i = -1 } },
	{ MODKEY | ShiftMask,                 XK_bracketleft,     shifttag,             { .i = -1 } },
	{ MODKEY,		                          XK_bracketright,    shiftview,            { .i = 1 } },
	{ MODKEY | ShiftMask,                 XK_bracketright,    shifttag,             { .i = 1 } },
	{ MODKEY | ShiftMask,                 XK_c,               killclient,           {0} },
	{ MODKEY | ControlMask,               XK_c,               killunsel,            {0} },
	{ MODKEY,                             XK_t,               setlayout,            {.v = &layouts[0]} },
	{ MODKEY,                             XK_e,               setlayout,            {.v = &layouts[1]} },
	{ MODKEY,                             XK_m,               setlayout,            {.v = &layouts[2]} },
	{ MODKEY,                             XK_slash,           cyclelayout,          {.i = +1 } },
	{ MODKEY | ShiftMask,		              XK_slash,           cyclelayout,          {.i = -1 } },
	{ MODKEY,                             XK_space,           setlayout,            {0} },
	{ MODKEY | ShiftMask,                 XK_space,           togglefloating,       {0} },
	{ MODKEY | ControlMask,               XK_j,               moveresize,           {.v = "0x 25y 0w 0h" } },
	{ MODKEY | ControlMask,               XK_k,               moveresize,           {.v = "0x -25y 0w 0h" } },
	{ MODKEY | ControlMask,               XK_l,               moveresize,           {.v = "25x 0y 0w 0h" } },
	{ MODKEY | ControlMask,               XK_h,               moveresize,           {.v = "-25x 0y 0w 0h" } },
	{ MODKEY | ControlMask | ShiftMask,   XK_j,               moveresize,           {.v = "0x 0y 0w 25h" } },
	{ MODKEY | ControlMask | ShiftMask,   XK_k,               moveresize,           {.v = "0x 0y 0w -25h" } },
	{ MODKEY | ControlMask | ShiftMask,   XK_l,               moveresize,           {.v = "0x 0y 25w 0h" } },
	{ MODKEY | ControlMask | ShiftMask,   XK_h,               moveresize,           {.v = "0x 0y -25w 0h" } },
	{ MODKEY,                             XK_f,               togglefullscreen,     {0} },
	{ MODKEY | ShiftMask,                 XK_f,               togglefakefullscreen, {0} },
	{ MODKEY,                             XK_0,               view,                 {.ui = ~0 } },
	{ MODKEY | ShiftMask,                 XK_0,               tag,                  {.ui = ~0 } },
	{ MODKEY,                             XK_comma,           focusmon,             {.i = -1 } },
	{ MODKEY,                             XK_period,          focusmon,             {.i = +1 } },
	{ MODKEY | ShiftMask,                 XK_comma,           tagmon,               {.i = -1 } },
	{ MODKEY | ShiftMask,                 XK_period,          tagmon,               {.i = +1 } },
	{ MODKEY,                             XK_F5,              xrdb,                 {.v = NULL } },
	{ MODKEY | ControlMask,               XK_q,               quit,                 {0} },
	{ MODKEY | ShiftMask,                 XK_q,               quit,                 {1} },
	{ MODKEY | ShiftMask,                 XK_r,               reorganizetags,       {0} },
	TAGKEYS(                              XK_1,                                     0)
	TAGKEYS(                              XK_2,                                     1)
	TAGKEYS(                              XK_3,                                     2)
	TAGKEYS(                              XK_4,                                     3)
	TAGKEYS(                              XK_5,                                     4)
	TAGKEYS(                              XK_6,                                     5)
	TAGKEYS(                              XK_7,                                     6)
	TAGKEYS(                              XK_8,                                     7)
	TAGKEYS(                              XK_9,                                     8)
};

/* button definitions */
/* click can be ClkButton, ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkButton,		        0,		          Button1,	      spawn,		      {.v = menu_cmd } },
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        layoutmenu,     {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkWinTitle,          MODKEY,         Button3,        killclient,     {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
