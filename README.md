#CF
---

CF solutions

this repo has solutions of some problems at CF(codeforces.com)

contact : won.seok.django@gmail.com

---

###Problem ID : Timofey and a tree(CF_DIV2_395_C.cpp)
[CF Round #395(Div.2)-C](http://codeforces.com/contest/764/problem/C)

This problem can be summarized as below.
> There is a colored tree, i.e. each vertex of tree has a color. Pick a single vertex ***v*** and make that vertex(***v***) as a root of given tree. It is not-annoying-tree if all of subtrees of ***v*** are composed with a signle color. Note that two different subtrees of ***v*** can be colored with different colors. The only thing Timofey have requested is that each subtree has to be colored with a single color. Below figure shows some examples of this problem description.

> ![TimofeyTreesExamples](https://github.com/wonseokdjango/CF/blob/master/images/TimofeyTreeExamples.png)

>> a. is annoying tree. Because subtree of root node(rooted at 2) has 2 colors.

>> b. is annoying tree. Because subtree of root node(rooted at 1) has 3 color.

>> c. is not annoying tree. Because all the subtrees of root node(rorted at 4, 5, 1) have a single color.

For efficient explaination, let's define an edge is **d-edge** when two vertices incident at this edge have a different color. Assume that there is a not annoying tree rooted at ***v***. In such case subtrees of ***v*** can not have a d-edge. If there is a d-edge in subtrees of ***v***, then tree rooted at ***v*** is not not-annoying-tree anymore.

> ![TimofeyNotAnnoying](https://github.com/wonseokdjango/CF/blob/master/images/TimofeyNotAnnoying.png)

When the number of d-edges in the given tree is |D|, we can say that if there is a vertex ***v*** which has a |D| incident d-edges then tree rooted at ***v*** is not-annoying-tree.

```c_cpp

// count d-edges.
int total = 0;
dedges.assign(n, 0); 
for (int idx = 0; idx < edges.size(); ++idx)
{   
    if (colors[edges[idx].first] != colors[edges[idx].second])
    {
        ++total;
        ++dedges[edges[idx].first];
        ++dedges[edges[idx].second];
    }

}   

// find root.
int idx;
for (idx = 0; idx < n; ++idx)
{   
    if (dedges[idx] == total)
        break;
}   

if (idx != n)
    printf("YES\n%d\n", idx + 1); 
else
    printf("NO\n");

```

---