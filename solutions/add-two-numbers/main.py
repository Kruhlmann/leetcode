class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1, l2):
        carry = 0
        output_n = ListNode(0)
        current_n = output_n
        while l1 is not None or l2 is not None:
            res = (l1.val if l1 else  0) + (l2.val if l2 else 0) + carry
            if res > 9:
                carry = 1
                res -= 10
            else:
                carry = 0
            this_n = ListNode(res)
            current_n.next = this_n
            current_n = current_n.next
            if l1 is not None:
                l1 = l1.next
            if l2 is not None:
                l2 = l2.next
        if carry == 1:
            current_n.next=ListNode(carry)
        return output_n.next
