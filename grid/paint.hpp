// グリッドdstの座標集合posで指定されたマスに色を塗る
// すでに塗られているかどうかにかによらず塗る
// returns := すでに塗られているマスを塗ったらtrue(is overlap?)
bool paint(const vector<pair<int,int>>& pos, vector<vector<int>>& dst) {
    bool overlap = false;
    for (const auto& [x,y] : pos) {
        if (dst[y][x]) {
            overlap = true;
        }
        dst[y][x] += 1;
    }
    return overlap;
}
// グリッドdstの座標集合posで指定されたマスの色を消す
// すでに塗られているかどうかにかによらず消す
void unpaint(const vector<pair<int,int>>& pos, vector<vector<int>>& dst) {
    for (const auto& [x,y] : pos) {
        dst[y][x] -= 1;
    }
}