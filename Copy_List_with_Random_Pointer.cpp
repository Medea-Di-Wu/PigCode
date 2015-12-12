/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)  return NULL;
        RandomListNode* node;
        if(m.find(head) != m.end()) {
            return m[head];
        }
        else {
            node = new RandomListNode(head->label);
            m[head] = node;
        }
        if(head->random != NULL) {
            if(m.find(head->random) != m.end()) {
                node->random = m[head->random];
            }
            else {
                node->random = copyRandomList(head->random);
            }
        }
        node->next = copyRandomList(head->next);
        return node;
    }
private:
    map <RandomListNode*, RandomListNode*> m;
};