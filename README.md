# MergeOfTwoLinkedList
合并两个有序的单链表,让新的链表继续保持有序,且使用原链表的结点.

## 上传目的
1. 复习常用数据结构
2. 良好的代码规范在 Xcode 中的应用.	<BR/>
	1> control + 6可以查看 pragma mark - 的详细信息<br/>
	2> option + 鼠标左键看函数或属性内容<br/>
	3> 代码提示中,包含注释中的内容

## 代码思路
1. 使用两个指针分别指向两个有序单链表的表头,移动指针比较数据域的内容.
2. 比较两个指针的数字域的大小,移动要归并的链表的表尾指针到数字较小的指针所在结点.
3. 将较小数字的单链表的指针向后移动一个单位,继续比较.
4. 当至少有一个链表为空的时候,将目的链表的结尾指针移向非空的链表,便得到合并后的链表.
