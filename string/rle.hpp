// 未テスト
// ランレングス符号化
vector<pair<char,int>> rle(const string& s) {
    assert(s.size() > 0);
    char now = s[0];
    int cnt = 0;
    vector<pair<char,int>> res;
    for (char c : s) {
        if (c == now) {
            ++cnt;
        }
        else {
            res.emplace_back(now, cnt);
            now = c;
            cnt = 1;
        }
    }
    res.emplace_back(now, cnt);
    return res;
}