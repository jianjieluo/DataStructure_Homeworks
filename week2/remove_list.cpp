void List::remove(int pos) {
  ListNode* p1 = head;
  for (int i = 1; i < pos; ++i) {
    if (p1->next == NULL) return;
    p1 = p1->next;
  }
  // ListNode* p2 = p1->next->next;
  ListNode* p2 = p1->next;
  p1->next = p2->next;
  delete p2;
  p2 = NULL;
}
