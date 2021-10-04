/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static int colorprompt = 1;                /* -p  option; if 1, prompt uses SchemeSel, otherwise SchemeNorm */
static int incremental = 1;                 /* -r  option; if 1, outputs text each time a key is pressed */
static int fuzzy = 1;                      /* -F  option; if 0, dmenu doesn't use fuzzy matching     */
static int centered = 1;                    /* -c option; centers dmenu on screen */
static int min_width = 1000;                    /* minimum width when centered */
static const unsigned int alpha = 0xb0;
/* -fn option overrides fonts[0]; default X11 font or font set */
static char font1[] = "monospace:size=10";
static char font2[] = "FiraCode Nerd Font:size=12";
static char *fonts[] = {
    font1,
    font2,
};
static char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static char *dynamic     = NULL;      /* -dy option; dynamic command to run on input change */
static char *symbol_1 = "<<";
static char *symbol_2 = ">>";

static char *colors[SchemeLast][10] = {
    /*     fg         bg       */
    [SchemeNorm] = { "#bbbbbb", "#222222", "#222222" },
    [SchemeSel] = { "#eeeeee", "#005577", "#005577" },
    [SchemeOut] = { "#000000", "#00ffff", "#00ffff" },
    [SchemeHighlight] = {"#f1fa8c", "#596377", "#3E485B"},
    [SchemeHover] = {"#ffffff", "#353D4B", "#3E485B"},
    [SchemeGreen] = {"#ffffff", "#52E067", "#41b252"},
    [SchemeRed] = {"#ffffff", "#e05252", "#c24343"},
    [SchemeYellow] = {"#ffffff", "#e0c452", "#bca33f"},
    [SchemeBlue] = {"#ffffff", "#5280e0", "#3a62b3"},
    [SchemePurple] = {"#ffffff", "#9952e0", "#7439b0"},
	[SchemeSelHighlight] = { "#ffc978", "#005577", "#005577" },
	[SchemeNormHighlight] = { "#ffc978", "#222222", "#222222" },
};
static unsigned int alphas[SchemeLast][2] = {
	[SchemeNorm] = { OPAQUE, alpha },
	[SchemeSel] = { OPAQUE, alpha },
	[SchemeOut] = { OPAQUE, alpha },
};

/* -l and -g options; controls number of lines and columns in grid if > 0 */
static unsigned int lines      = 0;
static unsigned int columns    = 0;

static unsigned int maxhist    = 64;
static int histnodup           = 1;	/* if 0, record repeated histories */
static unsigned int lineheight = 0; /* -h option; minimum height of a menu line     */
static unsigned int min_lineheight = 8;
static int sely = 0;
static int commented = 0;
static int animated = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 5;

/*
 * Use prefix matching by default; can be inverted with the -x flag.
 */
static int use_prefix = 1;

/* -n option; preselected item starting from 0 */
static unsigned int preselected = 1;

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
	{ "font1",        STRING, &font1 },
	{ "font2",        STRING, &font2 },
	{ "prompt",      STRING, &prompt },
	{ "colorprompt", INTEGER, &colorprompt },
	{ "incremental", INTEGER, &incremental },
	{ "fuzzy", INTEGER, &fuzzy },
	{ "centered", INTEGER, &centered },
	{ "min_width", INTEGER, &min_width },
	{ "prompt",        STRING, &prompt },
	{ "dynamic",        STRING, &dynamic },
	{ "symbol_1",        STRING, &symbol_1 },
	{ "symbol_2",        STRING, &symbol_2 },
	{ "lines", INTEGER, &lines },
	{ "columns", INTEGER, &columns },
	{ "maxhist", INTEGER, &maxhist },
	{ "histnodup", INTEGER, &histnodup },
	{ "lineheight", INTEGER, &lineheight },
	{ "min_lineheight", INTEGER, &min_lineheight },
	{ "sely", INTEGER, &sely },
	{ "commented", INTEGER, &commented },
	{ "animated", INTEGER, &animated },
	{ "worddelimiters",        STRING, &worddelimiters },
	{ "border_width", INTEGER, &border_width },
	{ "use_prefix", INTEGER, &use_prefix },
	{ "preselected", INTEGER, &preselected },
};
