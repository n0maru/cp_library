// y座標の反転
// h 反転前のy座標範囲[0, h)
// w 反転前のx座標範囲[0, w)
vector<pair<int,int>> flip_y(const vector<pair<int,int>>& pos, int h, int w) {
    vector<pair<int,int>> res;
    for (const auto& [x,y] : pos) {
        res.emplace_back(x, h-y-1);
    }
    return res;
}
// x座標の反転
// h 反転前のy座標範囲[0, h)
// w 反転前のx座標範囲[0, w)
vector<pair<int,int>> flip_x(const vector<pair<int,int>>& pos, int h, int w) {
    vector<pair<int,int>> res;
    for (const auto& [x,y] : pos) {
        res.emplace_back(w-x-1, y);
    }
    return res;
}