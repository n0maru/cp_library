template <
    void (*add_left)(int),       // 値xを左に追加する処理
    void (*add_right)(int),      // 値xを右に追加する処理
    void (*save)(),              // ロールバックするのに必要な情報を保存する
    void (*rollback)(),          // ロールバック処理
    void (*reset)(),             // 区間の長さを0にする　　ロールバックするための履歴を残すための変数もリセットする
    void (*record)(int)          // 答えの記録
>
struct RollbackMo {
    vector<int> ql,qr;

    RollbackMo() {}

    void add_query(int l, int r) {
        ql.emplace_back(l);
        qr.emplace_back(r);
    }

    void solve(int n) {
        const int q = ql.size();
        const int B = n / sqrt(q) + 1;                  // ブロックサイズ
        const int BL = (n+B-1)/B;                       // ブロック数

        vector<vector<int>> qid(BL);

        // 長さがB以下のクエリの処理
        for (int i = 0; i < q; ++i) {
            if (qr[i] - ql[i] <= B) {
                for (int j = ql[i]; j < qr[i]; ++j) {
                    add_right(j);
                }
                record(i);
                reset();
            }
            else {
                qid[ ql[i]/B ].push_back(i);
            }
        }

        // R[i]に基づいてソート
        for (int i = 0; i < BL; ++i) {
            sort(ALL(qid[i]),[&](int a, int b) {
                return qr[a] < qr[b];
            });
        }

        for (int t = 0; t < BL; ++t) {
            int lmax = 0;
            for (int i : qid[t]) lmax = max(lmax, ql[i]);   // 基準点lmaxを求める
            int r = lmax;
            for (int i : qid[t]) {
                while (r < qr[i]) add_right(r++);           // 右に伸ばす
                save();                                     // 右に伸ばした分を保存
                int l = lmax;
                while (ql[i] < l) add_left(--l);            // 左に伸ばす
                record(i);                                  // 答えを求める
                rollback();                                 // 左に伸ばした分をロールバック
            }
            // 右に伸ばした分をリセット
            reset();
        }
    }
};
/*
void add_left(int i) {

}
void add_right(int i) {

}
void save() {

}
void rollback() {

}
void reset() {

}
void record() {
    
}
*/