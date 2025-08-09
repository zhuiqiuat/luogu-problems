#include <bits/stdc++.h>
using namespace std;

string x(string s1,string s2){
  vector<int> a;
  vector<int> b;
  vector<int> c;
  for(int i = s1.size() - 1;i >= 0;i--){
    a.push_back(s1[i] - '0');
  }
  for(int i = s2.size() - 1;i >= 0;i--){
    b.push_back(s2[i] - '0');
  }
  for(auto i = 0;i < b.size();i++){
    for(auto j = 0;j < a.size();j++){
      int ans = b[i] * a[j];
      if(i + j == c.size()){
        c.push_back(ans);
      }else{
        c[i + j] += ans;
      }
    }
  }
  for(auto i = 0;i < c.size();i++){
    int tmp = c[i] / 10;
    c[i] %= 10;
    if(tmp != 0){
      if(i + 1 < c.size()){
        c[i + 1] += tmp;
      }else{
        c.push_back(tmp);
      }
    }
  }
  string ans = "";
  for(auto i = 0;i < c.size();i++){
    ans.insert(0,to_string(c[i]));
    // ans = (c[i] + '0') + ans;
  }
  while(ans[0] == '0' && ans.size() > 1){
    ans.erase(0,1);
  }

  return ans;
}

int main()
{
  // 请在此输入您的代码
  string s1,s2;
  cin >> s1 >> s2;
  string num1 = "1";
  int count = stoi(s1);
  for(int i = 1;i <= count;i++){
    num1 = x(num1,"2");
  }
  // cout << "num1 = " << num1;
  int dot = s2.find(".");
  int tmp = s2.size() - dot - 1;
  s2.erase(dot,1);
  while(s2[0] == '0' && s2.size() > 1){
    s2.erase(0,1);
  }
  string num2 = x(num1,s2);
  while(num2.size() < tmp + 1){
    num2.insert(0,"0");
  }
  // num2.insert(num2.size() - dot - 1,".");
  // cout << num2.size() - dot - 1 << "\n";
  // cout << num2 << "\n";
  string ans = num2.substr(0,num2.size() - tmp);
  char c = num2[num2.size() - tmp];
  // cout << c << "\n";
  if(c >= '5') ans[ans.size() - 1]++;
  for(int i = ans.size() - 1;i >= 0;i--){
    if(ans[i] > '9'){
      if(i != 0){
        ans[i - 1]++;
        ans[i] -= 10;
      }else{
        ans[i] -= 10;
        ans = "1" + ans;
      }
    }
  }
  cout << ans;
  return 0;
}