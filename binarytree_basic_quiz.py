from random import randint

# for binary search tree, basic implementation
class node:
    def __init__(self, value=None, left=None, right=None):
        self.left = left
        self.right = right
        self.value = value

# SOURCE: https://www.tutorialspoint.com/python_data_structure/python_binary_tree.htm
    def insert(self, data):
        if self.value:
            if data < self.value:
                if self.left is None:
                    self.left = node(data)
                else:
                    self.left.insert(data)
            elif data > self.value:
                if self.right is None:
                    self.right = node(data)
                else:
                    self.right.insert(data)
        else:
            self.value = data


# SOURCE: https://leetcode.com/discuss/interview-question/1954462/pretty-printing-binary-trees-in-python-for-debugging
def display(root):
    lines, *_ = _display_aux(root)
    for line in lines:
        print(line)

def _display_aux(self):
    """Returns list of strings, width, height, and horizontal coordinate of the root."""
    # No child.
    if self.right is None and self.left is None:
        line = '%s' % self.value
        width = len(line)
        height = 1
        middle = width // 2
        return [line], width, height, middle

    # Only left child.
    if self.right is None:
        lines, n, p, x = _display_aux(self.left)
        s = '%s' % self.value
        u = len(s)
        first_line = (x + 1) * ' ' + (n - x - 1) * '_' + s
        second_line = x * ' ' + '/' + (n - x - 1 + u) * ' '
        shifted_lines = [line + u * ' ' for line in lines]
        return [first_line, second_line] + shifted_lines, n + u, p + 2, n + u // 2

    # Only right child.
    if self.left is None:
        lines, n, p, x = _display_aux(self.right)
        s = '%s' % self.value
        u = len(s)
        first_line = s + x * '_' + (n - x) * ' '
        second_line = (u + x) * ' ' + '\\' + (n - x - 1) * ' '
        shifted_lines = [u * ' ' + line for line in lines]
        return [first_line, second_line] + shifted_lines, n + u, p + 2, u // 2

    # Two children.
    left, n, p, x = _display_aux(self.left)
    right, m, q, y = _display_aux(self.right)
    s = '%s' % self.value
    u = len(s)
    first_line = (x + 1) * ' ' + (n - x - 1) * '_' + s + y * '_' + (m - y) * ' '
    second_line = x * ' ' + '/' + (n - x - 1 + u + y) * ' ' + '\\' + (m - y - 1) * ' '
    if p < q:
        left += [n * ' '] * (q - p)
    elif q < p:
        right += [m * ' '] * (p - q)
    zipped_lines = zip(left, right)
    lines = [first_line, second_line] + [a + u * ' ' + b for a, b in zipped_lines]
    return lines, n + m + u, max(p, q) + 2, n + u // 2
# -----------------------------------------------------------------------

# TREE TRAVERSAL --------------------------------------------------------

# left, right, visit
# uses: delete a tree
def post_order(node):

    if node.left:   post_order(node.left)
    if node.right:  post_order(node.right)
    print(node.value, end=' ')


# visit, left, right
# uses: create a copy of the tree
def pre_order(node):

    print(node.value, end=' ')
    if node.left:   pre_order(node.left)
    if node.right:  pre_order(node.right)

# left, visit, right
def in_order(node):

    if node.left:   in_order(node.left)
    print(node.value, end=' ')
    if node.right:  in_order(node.right)

# -----------------------------------------------------------------------


# generate binary search tree using randomly generated numbers
head = node()
[head.insert(randint(0, 25)) for i in range(0,15)]

display(head)

response = None

while response not in ('y', 'yes'):

    response = input('Show in-, pre-, and post-order? ')



print()
print("Post Order")
post_order(head)
print()
print()

print("Pre Order")
pre_order(head)
print()

print("\nIn Order")
in_order(head)
print()
