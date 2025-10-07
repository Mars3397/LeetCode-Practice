class Solution {
    using LL = long long;
    struct Key {
        int sx, sy;   // xi+xj, yi+yj
        LL len2;      // diagonal squared length
        bool operator==(const Key& o) const {
            return sx==o.sx && sy==o.sy && len2==o.len2;
        }
    };
    struct KeyHash {
        size_t operator()(const Key& k) const {
            // 混合雜湊
            size_t h = (uint64_t(k.sx) << 32) ^ uint32_t(k.sy);
            h ^= std::hash<LL>{}(k.len2) + 0x9e3779b97f4a7c15ULL + (h<<6) + (h>>2);
            return h;
        }
    };
    static inline LL dist2(const vector<int>& a, const vector<int>& b) {
        LL dx = (LL)a[0]-b[0], dy = (LL)a[1]-b[1];
        return dx*dx + dy*dy;
    }
public:
    double minAreaFreeRect(vector<vector<int>>& pts) {
        int n = pts.size();
        unordered_map<Key, vector<pair<int,int>>, KeyHash> buckets;
        buckets.reserve(n*n*2);

        // 1) 對角線分桶
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                Key k{pts[i][0]+pts[j][0], pts[i][1]+pts[j][1], dist2(pts[i], pts[j])};
                buckets[k].push_back({i,j});
            }
        }

        long double best = numeric_limits<long double>::infinity();

        // 2) 同桶兩兩配對
        for (auto& [k, vec] : buckets) {
            int m = (int)vec.size();
            if (m < 2) continue;
            for (int a = 0; a < m; ++a) {
                auto [i, j] = vec[a];
                for (int b = a+1; b < m; ++b) {
                    auto [r, s] = vec[b];
                    // 面積 = |pi - pr| * |pi - ps|
                    LL d1 = dist2(pts[i], pts[r]);
                    LL d2 = dist2(pts[i], pts[s]);
                    long double area = sqrt((long double)d1) * sqrt((long double)d2);
                    if (area < best && area > 0) best = area;
                }
            }
        }
        return std::isinf(best) ? 0.0 : (double)best;
    }
};
