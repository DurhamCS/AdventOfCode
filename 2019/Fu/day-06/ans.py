import os

class Tree():
    def __init__(self,name=None,depth=0,child=[]):
        self.name = name
        self.depth = depth
        self.child = child
    def dis_line(self):
        return [self.name] + [n.dis_line() for n in self.child]
    def get_des(self):
        a = [self.name]
        for n in self.child:
            a += n.get_des()
        return a
    def ins_child_tree(self,s,sub):
        if self.name == s:
            sub.depth = self.depth + 1
            self.child.append(sub)
        else:
            for n in self.child:
                n.ins_child_tree(s,sub)
    def ins_child_trees(self,s,sub_arr):
        if self.name == s:
            for n in sub_arr:
                n.depth = self.depth + 1
                self.child.append(n)
        else:
            for n in self.child:
                n.ins_child_trees(s,sub_arr)
    def upd_dep(self,d):
        self.depth = d
        for n in self.child:
            n.upd_dep(d+1)

with open(os.path.dirname(__file__)+"/test_inp.txt") as f:
    l = [n.strip() for n in f.readlines()]
    l = [n.split(")") for n in l]

trees = []
k = 0
for s,o in l:
    print(k,len(trees));k+=1
    for i,tree in enumerate(trees):
        if s in des_memo[i]: #add o tree's child's child
            tree.ins_child_tree(s,Tree(o,0,[]))
        elif o == tree.name: #set s as new root of tree
            trees[i] = Tree(s,0,[tree])
            trees[i].upd_dep(0)
    else:
        trees.append(Tree(s,0,[Tree(o,1,[])])) #gen new tree
    #combine trees
    for i in range(len(trees)-1,-1,-1):
        name = trees[i].name
        d = False
        for j in range(len(trees)-1,-1,-1):
            if not d and i != j and name in trees[j].get_des():
                for n in trees[i].child:
                    trees[j].ins_child_tree(name,n)
                d = True
        if d: trees.pop(i)
    des_memo = [n.get_des() for n in trees]
    print([len(n) for n in des_memo])