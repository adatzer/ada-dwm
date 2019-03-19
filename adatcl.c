void
tcl(Monitor * m)
{
	/*int x, y, h, w, mw, sw, bdw;*/
	unsigned int i, n, x, y, h, w, mw, sw, bdw;
	Client * c;

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
	if (n == 0)
		return;

	c = nexttiled(m->clients);

	mw = m->mfact * m->ww;
	sw = (m->ww - mw) / 2;
	bdw = (2 * c->bw);
	resize(c,
	       n < 3 ? m->wx + 2*m->gappx : m->wx + sw + 4*m->gappx, /* start x-coords:left : middle */
	       m->wy + m->gappx,
	       n == 1 ? m->ww - bdw - 2*m->gappx : mw - bdw - 7*m->gappx,
	       m->wh - bdw - m->gappx,
	       False);

	if (--n == 0)
		return;

	w = (m->ww - mw) / ((n > 1) + 1);
	c = nexttiled(c->next);

	if (n > 1)
	{
		x = m->wx + ((n > 1) ? mw + sw + 0*m->gappx : mw + m->gappx);
		y = m->wy + m->gappx;
		h = (m->wh - (n - (n%2))*m->gappx) / (n / 2);

		if (h < bh)
			h = m->wh;

		for (i = 0; c && i < n / 2; c = nexttiled(c->next), i++)
		{
			resize(c,
			       x,
			       y,
			       w - bdw - 2*m->gappx,
			       (i + 1 == n / 2) ? m->wy + m->wh - y - bdw : h - bdw,
			       False);

			if (h != m->wh)
				y = c->y + HEIGHT(c) + 2*m->gappx;
		}
	}

	x = (n + 1 / 2) == 1 ? mw + 0*m->gappx : m->wx + m->gappx;
	y = m->wy + m->gappx;
	h = (m->wh - (n - (n%2))*m->gappx) / ((n + 1) / 2);

	if (h < bh)
		h = m->wh;

	for (i = 0; c; c = nexttiled(c->next), i++)
	{
		resize(c,
		       x,
		       y,
		       w - bdw - 1*m->gappx,   /* width of leftmost column */
		       (i + 1 == (n + 1) / 2) ? m->wy + m->wh - y - bdw : h - bdw,
		       False);

		if (h != m->wh)
			y = c->y + HEIGHT(c) + 2*m->gappx;
	}
}
