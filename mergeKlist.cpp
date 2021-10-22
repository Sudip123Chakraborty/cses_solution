#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*> head) {
    //Complete the function
    int flag = 1;
    int n = head.size();
    vector<int> num;
    while(flag){
        vector<int> temp(n, 1000000001);
        flag=0;
        int minindex = -1;
        int min = 1e9+2;
        for (int i = 0; i < n; i++)
        {
            if(head[i]!=nullptr){
                flag = 1;
                temp[i] = head[i]->val;
                if(temp[i]<min){
                    min = temp[i];
                    minindex = i;
                }
            }
        }
        if(flag){
            head[minindex]=head[minindex]->next;
            num.push_back(min);

        }
        
    }
    ListNode* head1 = nullptr;

    if(num.empty()) {
        return head1;
    }

    ListNode* cur = head1;
    
    for(int i  = 0; i < (int)num.size(); i++) {
        ListNode* temp = new ListNode(num[i]);
        if(!cur) {
            cur = temp;
            head1 = cur;
        }
        else {
            cur->next = temp;
            cur = temp;
        }
    }
    
    return head1;


}

ListNode* GetList(vector<int> &num) {
    ListNode* head = nullptr;

    if(num.empty()) {
        return head;
    }

    ListNode* cur = head;
    
    for(int i  = 0; i < (int)num.size(); i++) {
        ListNode* temp = new ListNode(num[i]);
        if(!cur) {
            cur = temp;
            head = cur;
        }
        else {
            cur->next = temp;
            cur = temp;
        }
    }
    
    return head;
}

vector<ListNode*> GetList(int K, vector<vector<int>> &num) {
    vector<ListNode*> head(K);
    for(int i = 0; i < K; i++) {
        head[i] = GetList(num[i]);
    }
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K;
    cin >> K;

    vector<vector<int>> num(K);

    for(int i = 0; i < K; i++) {
        int n;
        cin >> n;
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            num[i].push_back(x);
        }
    }

    vector<ListNode*> head = GetList(K, num);

    ListNode* mergeHead = mergeKLists(head);

    while(mergeHead) {
        cout << mergeHead->val << " ";
        mergeHead = mergeHead->next;
    }
    cout << "\n";
    
    return 0;
}