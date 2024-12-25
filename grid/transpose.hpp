// 転置
// pos 対象の座標
// h 転置前のy座標範囲[0, h)
// w 転置前のx座標範囲[0, w)
vector<pair<int,int>> transpose(const vector<pair<int,int>>& pos, int h, int w) {
    vector<pair<int,int>> res;
    for (const auto& [x,y] : pos) {
        int nx = y;
        int ny = x;
        res.emplace_back(nx, ny);
    }
    return res;
}