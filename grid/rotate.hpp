// 回転
// h 回転前のy座標範囲[0, h)
// w 回転前のx座標範囲[0, w)
// 必要：transpose, flip_xかflip_y
vector<pair<int,int>> rotate(const vector<pair<int,int>>& pos, int h, int w) {
    auto res = transpose(pos, h, w);
    res = flip_x(res, w, h); // 右回転
    // res = flip_y(res, w, h); // 左回転
    return res;
}