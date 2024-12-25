// 平行移動
// h 移動後のy座標範囲[0, h)
// w 移動後のx座標範囲[0, w)
// returns.second := すべてが左上(0,0)右下(w-1,h-1)の範囲に入っているならtrue
pair<vector<pair<int,int>>,bool> translate(const vector<pair<int,int>>& pos, int dx, int dy, int h, int w) {
    vector<pair<int,int>> res;
    bool inside = true;
    for (const auto& [x,y] : pos) {
        int nx = x + dx;
        int ny = y + dy;
        if (!(0 <= nx && nx < w && 0 <= ny && ny < h)) inside = false;
        res.emplace_back(nx, ny);
    }
    return {res,inside};
}