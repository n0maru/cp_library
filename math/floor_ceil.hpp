#pragma once
// a/bの結果を正の方向へ丸める
ll ceil(ll x, ll y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    return (x > 0 ? (x + y - 1) / y : x / y);
}

// a/bの結果を負の方向へ丸める
ll floor(ll x, ll y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    return (x > 0 ? x / y : (x - y + 1) / y);
}