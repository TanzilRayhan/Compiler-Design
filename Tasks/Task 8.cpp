#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define nl '\n'
#define all(x) x.begin(), x.end()
#ifdef LOKAL
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif

void solve()
{

    string expression; ;
    getline(cin, expression);

    istringstream iss(expression);
    vector<string> id;
    for (string s; iss >> s;)
        id.push_back(s);

    int t_no = 1;
    string st = "";
    cout << "Given Expression: " << expression << nl;

    cout << "---Three address code---" << nl;
    for (int i = 2; i < id.size(); i += 2)
    {
        if (t_no > 3)
            break;
        st = id[i] + id[i + 1] + id[i + 2];

        cout << "t" << t_no << " = " << st << nl;

        id[i + 2] = "t" + to_string(t_no);
        ++t_no;
    }
    st.clear();
    --t_no;
    st = id[0] + ' ' + id[1] + " t" + to_string(t_no);
    cout << st << nl;
    st.clear();
}

signed main()
{
#ifndef LOKAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    solve();
    return 0;
}
