// max integer less than or equal to \sqrt{x}
ll sqrt_le(ll x) {
	ll ok = 0, ng = x+1;
	while (ng - ok > 1) {
		ll mid = ok + (ng - ok) / 2;
		(mid <= x / mid ? ok : ng) = mid;
	}
	return ok;
}

// max integer less than \sqrt{x}
ll sqrt_lt(ll x) {
	if (x == 0) return -1;
	ll ok = 0, ng = x+1;
	while (ng - ok > 1) {
		ll mid = ok + (ng - ok) / 2;
		(mid < (x+mid-1) / mid ? ok : ng) = mid;
	}
	return ok;
}