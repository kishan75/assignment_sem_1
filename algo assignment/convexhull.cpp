#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fs first
#define ss second
pii mid;

// get quadrant number, used in compare function for sorting according to clock wise
int get_quadrant(pii p)
{
    if (p.fs >= 0 && p.ss >= 0)
        return 1;
    if (p.fs <= 0 && p.ss >= 0)
        return 2;
    if (p.fs <= 0 && p.ss <= 0)
        return 3;
    return 4;
}

// get slope of points
int get_slope(pii a, pii b,pii c)
{
    int res = (b.ss-a.ss)*(c.fs-b.fs)-(c.ss-b.ss)*(b.fs-a.fs);
    if (res == 0)
        return 0;
    if (res > 0)
        return 1;
    return -1;
}

//compare function for sorting according to clockwise
bool compare(pii p1, pii q1)
{
    pii p = mp(p1.fs - mid.fs,p1.ss - mid.ss);
    pii q = mp(q1.fs - mid.fs,q1.ss - mid.ss);
    int one = get_quadrant(p);
    int two = get_quadrant(q);
    if (one != two)
        return (one < two);
    return (p.ss*q.fs < q.ss*p.fs);
}

vector<pii> merge(vector<pii> a,vector<pii> b)
{
    int n1 = a.size(), n2 = b.size();
    int ia = 0, ib = 0;
    for (int i=1; i<n1; i++)
        if (a[i].fs > a[ia].fs)
            ia = i;
    for (int i=1; i<n2; i++)
        if (b[i].fs < b[ib].fs)
            ib=i;
    // finding the upper tangent
    int inda = ia, indb = ib;
    bool done = 0;
    while (!done)
    {
        done = 1;
        while (get_slope(b[indb], a[inda], a[(inda+1)%n1]) >=0)
            inda = (inda + 1) % n1;
        while (get_slope(a[inda], b[indb], b[(n2+indb-1)%n2]) <=0)
        {
            indb = (n2+indb-1)%n2;
            done = 0;
        }
    }
    int uppera = inda, upperb = indb;
    inda = ia, indb=ib;
    done = 0;
    int g = 0;
    while (!done)//finding the lower tangent
    {
        done = 1;
        while (get_slope(a[inda], b[indb], b[(indb+1)%n2])>=0)
            indb=(indb+1)%n2;
        while (get_slope(b[indb], a[inda], a[(n1+inda-1)%n1])<=0)
        {
            inda=(n1+inda-1)%n1;
            done=0;
        }
    }
    int lowera = inda, lowerb = indb;
    vector<pii> res;
    //res contains the convex hull after merging the two convex hulls
    //with the points sorted in anti-clockwise order
    int ind = uppera;
    res.pb(a[uppera]);
    while (ind != lowera)
    {
        ind = (ind+1)%n1;
        res.pb(a[ind]);
    }
    ind = lowerb;
    res.pb(b[lowerb]);
    while (ind != upperb)
    {
        ind = (ind+1)%n2;
        res.pb(b[ind]);
    }
    return res;
}
// Brute force algorithm to find convex hull for less than 6 points
vector<pii> brute_force(vector<pii> a)
{
    set<pii>s;
    for (int i=0; i<a.size(); i++)
    {
        for (int j=i+1; j<a.size(); j++)
        {
            int x1 = a[i].fs, x2 = a[j].fs;
            int y1 = a[i].ss, y2 = a[j].ss;
            int a1 = y1-y2;
            int b1 = x2-x1;
            int c1 = x1*y2-y1*x2;
            int pos = 0, neg = 0;
            for (int k=0; k<a.size(); k++)
            {
                if (a1*a[k].fs+b1*a[k].ss+c1 <= 0)
                    neg++;
                if (a1*a[k].fs+b1*a[k].ss+c1 >= 0)
                    pos++;
            }
            if (pos == a.size() || neg == a.size())
            {
                s.insert(a[i]);
                s.insert(a[j]);
            }
        }
    }
    vector<pii>res;
    for (auto e:s)
        res.pb(e);
    // Sorting the points in the anti-clockwise order
    mid = {0, 0};
    int n = res.size();
    for (int i=0; i<n; i++)
    {
        mid.fs += res[i].fs;
        mid.ss += res[i].ss;
        res[i].fs *= n;
        res[i].ss *= n;
    }
    sort(res.begin(), res.end(), compare);
    for (int i=0; i<n; i++)
        res[i] = mp(res[i].fs/n, res[i].ss/n);
    return res;
}

vector<pii> divide(vector<pii> a)
{
    if (a.size() <= 5)
        return brute_force(a);

    vector<pii>left, right;
    for (int i=0; i<a.size()/2; i++)
        left.pb(a[i]);
    for (int i=a.size()/2; i<a.size(); i++)
        right.pb(a[i]);

    vector<pii>left_hull = divide(left);
    vector<pii>right_hull = divide(right);

    return merge(left_hull, right_hull);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<pii> a;
    int n,num1,num2;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num1>>num2;
        a.pb(mp(num1, num2));
    }

    sort(a.begin(), a.end());

    vector<pii>ans = divide(a);
    
    cout << "points : \n";
    
    for (int i=0;i<ans.size();i++)
       cout << ans[i].fs <<" "<< ans[i].ss << endl;
    return 0;
}