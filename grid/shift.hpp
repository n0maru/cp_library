// x+方向循環シフト
// h シフト前のy座標範囲[0, h)
// w シフト前のx座標範囲[0, w)
vector<pair<int,int>> shift_x_plus(const vector<pair<int,int>>& pos, int h, int w) {
    vector<pair<int,int>> res;
    for (const auto& [x,y] : pos) {
        res.emplace_back((x+1)%w, y);
    }
    return res;
}
// x-方向循環シフト
// h シフト前のy座標範囲[0, h)
// w シフト前のx座標範囲[0, w)
vector<pair<int,int>> shift_x_minus(const vector<pair<int,int>>& pos, int h, int w) {
    vector<pair<int,int>> res;
    for (const auto& [x,y] : pos) {
        res.emplace_back((x-1+w)%w, y);
    }
    return res;
}
// y+方向循環シフト
// h シフト前のy座標範囲[0, h)
// w シフト前のx座標範囲[0, w)
vector<pair<int,int>> shift_y_plus(const vector<pair<int,int>>& pos, int h, int w) {
    vector<pair<int,int>> res;
    for (const auto& [x,y] : pos) {
        res.emplace_back(x, (y+1)%h);
    }
    return res;
}
// y-方向循環シフト
// h シフト前のy座標範囲[0, h)
// w シフト前のx座標範囲[0, w)
vector<pair<int,int>> shift_y_minus(const vector<pair<int,int>>& pos, int h, int w) {
    vector<pair<int,int>> res;
    for (const auto& [x,y] : pos) {
        res.emplace_back(x, (y-1+h)%h);
    }
    return res;
}