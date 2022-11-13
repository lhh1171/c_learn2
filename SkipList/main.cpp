#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    int key;
    // forward: means for each level, the node next pointer to which node.
    // 表示每个级别的节点下一个指针指向哪个节点。
    vector<Node *> forward;

    Node(int key, int level) {
        this->key = key;
        this->forward = vector<Node *>(level + 1);
    }
};

class SkipList {
public:
    Node *head;
    int MAX_LEVEL = 10;
    float p = 0.1;
    int level = 0;

    SkipList() {
        this->head = new Node(-1, MAX_LEVEL + 1);
    }

    int randomLevel() const {
        float r = (float) rand() / RAND_MAX;

        int lvl = 0;
        //当随机数小于0.1时候，lvl加1，
        while (r < p && lvl < MAX_LEVEL) {
            lvl++;
            cout<<"\nr: "<<r<<" lvl: "<<lvl;
            //当随机数小于0.1时候，lvl继续加1
            r = (float) rand() / RAND_MAX;
        }
        return lvl;
    }

    void insert(int key) {
        auto updated = vector<Node *>(MAX_LEVEL + 1);
        //获取当前链表的头结点
        auto cur = this->head;
        //每一层，检测每个级别的节点的下一个指针是否为空且其key是否小于要插入的key
        //如果小于就获取该层，表示要更新该层
        for (int i = this->level; i >= 0; i--) {
            while (cur->forward[i] != nullptr && cur->forward[i]->key < key) {
                cur = cur->forward[i];
            }
            updated[i] = cur;
        }

        cur = cur->forward[0];

        // cur == nullptr: the end of list, cur->key!=key means found the position to insert.
        //cur==nullptr：列表的末尾，cur->key!=key 表示找到要插入的位置。
        if (cur == nullptr || cur->key != key) {
            auto lvl = this->randomLevel();
            //当随机lvl大于list的level时候，当前level加一
            if (lvl > this->level) {
                for (int i = this->level + 1; i <= lvl; i++) {
                    updated[i] = this->head;
                }
                this->level = lvl;
            }

            Node *newNode = new Node(key, lvl);

            for (int i = 0; i <= lvl; i++) {
                newNode->forward[i] = updated[i]->forward[i];
                updated[i]->forward[i] = newNode;
            }
        }
    }

    bool search(int key) const {
        auto cur = this->head;
        for (int i = this->level; i >= 0; i--) {
            while (cur->forward[i] != nullptr && cur->forward[i]->key < key) {
                cur = cur->forward[i];
            }
        }
        cur = cur->forward[0];
        return cur != nullptr && cur->key == key;
    }

    void deleteByKey(int key) {
        auto updated = vector<Node *>(MAX_LEVEL + 1);
        auto cur = this->head;
        for (int i = this->level; i >= 0; i--) {
            while (cur->forward[i] != nullptr && cur->forward[i]->key < key) {
                cur = cur->forward[i];
            }
            updated[i] = cur;
        }
        cur = cur->forward[0];
        if (cur->key != key) {
            return;
        }
        for (int i = cur->forward.size() - 1; i >= 0; i--) {
            updated[i]->forward[i] = updated[i]->forward[i]->forward[i];
        }
        delete (cur);

        while (this->level > 0 && this->head->forward[this->level] == nullptr) {
            this->level--;
        }
    }

    void showList() const {
        cout << "----skip list------" << endl;
        for (int i = 0; i <= level; i++) {
            auto cur = this->head->forward[i];
            while (cur != nullptr) {
                cout << cur->key;
                if (cur->forward[i] != nullptr) {
                    cout << "->";
                }
                cur = cur->forward[i];
            }
            cout << "\n";
        }
    }
};

int main() {
    auto list = new SkipList();
//    list->insert(1);
//    list->insert(2);
//    list->insert(5);
//    list->insert(3);
//    list->insert(4);
//    list->insert(7);
//    list->insert(6);
//    list->insert(9);
//
//    list->insert(15);
//    list->insert(13);
//    list->insert(14);
//    list->insert(17);
//    list->insert(16);
//    list->insert(19);
//    list->insert(25);
//    list->insert(23);
//    list->insert(24);
//    list->insert(27);
//    list->insert(26);
//    list->insert(29);
    for (int i = 0; i < 10000000; ++i) {
        list->insert(i);
    }
    list->showList();
    list->deleteByKey(5);
    list->showList();


    cout << list->search(4) << endl;
    return 0;
}