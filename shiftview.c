/* Navigate to the next/prev tag */
void
shiftview(const Arg *arg)
{
	Arg shifted;
	Client *c;
	unsigned int tagmask = 0;

  // Uncomment this if you want to move between vacant tags.
	// if (arg->i > 0) // left circular shift
	// 	shifted.ui = (selmon->tagset[selmon->seltags] << arg->i)
	// 	             | (selmon->tagset[selmon->seltags] >> (LENGTH(tags) - arg->i));

	// else // right circular shift
	// 	shifted.ui = selmon->tagset[selmon->seltags] >> (- arg->i)
	// 	             | selmon->tagset[selmon->seltags] << (LENGTH(tags) + arg->i);

	for (c = selmon->clients; c; c = c->next)
#if SCRATCHPADS_PATCH
		if (!(c->tags & SPTAGMASK)) {
			tagmask = tagmask | c->tags;
		}
#else
		tagmask = tagmask | c->tags;
#endif // SCRATCHPADS_PATCH

#if SCRATCHPADS_PATCH
	shifted.ui = selmon->tagset[selmon->seltags] & ~SPTAGMASK;
#else
	shifted.ui = selmon->tagset[selmon->seltags];
#endif // SCRATCHPADS_PATCH
	if (arg->i > 0) // left circular shift
		do {
			shifted.ui = (shifted.ui << arg->i)
			             | (shifted.ui >> (LENGTH(tags) - arg->i));
#if SCRATCHPADS_PATCH
			shifted.ui &= ~SPTAGMASK;
#endif // SCRATCHPADS_PATCH
		} while (tagmask && !(shifted.ui & tagmask));
	else // right circular shift
		do {
			shifted.ui = (shifted.ui >> (- arg->i)
			              | shifted.ui << (LENGTH(tags) + arg->i));
#if SCRATCHPADS_PATCH
			shifted.ui &= ~SPTAGMASK;
#endif // SCRATCHPADS_PATCH
		} while (tagmask && !(shifted.ui & tagmask));

	view(&shifted);
}

/* Sends a window to the next/prev tag */
void
shifttag(const Arg *arg)
{
	Arg shifted;
	shifted.ui = selmon->tagset[selmon->seltags];


	if (arg->i > 0) {	/* left circular shift */
		shifted.ui = ((shifted.ui << arg->i) | (shifted.ui >> (LENGTH(tags) - arg->i)));
	} else {	/* right circular shift */
		shifted.ui = (shifted.ui >> (- arg->i) | shifted.ui << (LENGTH(tags) + arg->i));
	}
	tag(&shifted);
}
