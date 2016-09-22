
void List::insert(int toadd, int pos) {
  ListNode* p = head;
  for (int i = 1; i < pos; ++i) {
    if (p->next == NULL) return;
    p = p->next;
  }
  ListNode* temp = new ListNode;
  temp->data = toadd;
  temp->next = p->next;
  p->next = temp;
}
