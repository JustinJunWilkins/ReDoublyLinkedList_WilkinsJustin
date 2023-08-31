#include "pch.h"
#include "class.h"
class NoReferenceConstructor {
public:
	NoReferenceConstructor(int value) : value(value){}
	int getValue() {
		return value;
	}
private:
		int value;
};//リストの参照がないコンストラクタ―を用意
//iteratorの指す要素を取得する
TEST(GetTheElementPointedToByTheIterator, BehaviorWhenCalledWithNoListReferenceIt) {//リストの参照がない状態で呼び出した際の挙動(Iterator)
	DoublyLinkedList list;
	NoReferenceConstructor Constructor(1);
	DoublyLinkedList::Iterator it = list.begin();
	ASSERT_DEATH(*it, ".*");
}
TEST(GetTheElementPointedToByTheIterator, BehaviorWhenCalledWithNoListReferenceConstIt) {//リストの参照がない状態で呼び出した際の挙動(ConstIterator)
	DoublyLinkedList list;
	NoReferenceConstructor Constructor(1);
	DoublyLinkedList::ConstIterator it = list.begin();
	ASSERT_DEATH(*it, ".*");
}
TEST(GetTheElementPointedToByTheIterator, CheckWhetherAValueCanBeAssignedToAnElementRetrievedFromTheIterator) {//Iteratorから取得した要素に対して、値の代入が行えるかをチェック
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	auto it = list.begin();
	EXPECT_EQ(1, (*it).score);
	(*it).score = 2;
	EXPECT_EQ(2, (*it).score);
	EXPECT_EQ("name1", (*it).username);
}
TEST(GetTheElementPointedToByTheIterator, CheckWhetherAValueCanBeAssignedToAnElementRetrievedFromAConstIterator) {//ConstIteratorから取得した要素に対して、値の代入が行えないかをチェック
	DoublyLinkedList list;
	list.Constinsert(list.begin(), 1, "name1");
	auto it = list.begin();
	EXPECT_EQ(1, (*it).score);
	(*it).score = 2;
	EXPECT_EQ(2, (*it).score);
}
TEST(GetTheElementPointedToByTheIterator, BehaviorWhenCallingOnTheFirstIteratorWhenTheListIsEmpty) {//リストが空の際の、先頭イテレータに対して呼び出した際の挙動
	DoublyLinkedList list;
	auto it = list.begin();
	ASSERT_DEATH(*it, ".*");
}
TEST(GetTheElementPointedToByTheIterator, BahaviorWhenCalledOnTheTailIterator) {//末尾イテレータに対して呼び出した際の挙動
	DoublyLinkedList list;
	auto it = list.end();
	ASSERT_DEATH(*it, ".*",);
}

//iteratorをリストの末尾に向かって一つ進める
TEST(AdvanceIteratorByOneTowardTheEndOfTheList, BehaviorWhenCalledWithNoListReference) {//リストの参照がない状態で呼び出した際の挙動
	DoublyLinkedList::Iterator it=nullptr;
	auto adit = ++it;
	ASSERT_DEATH(*adit, ".*");
}
TEST(AdvanceIteratorByOneTowardTheEndOfTheList, BehaviorWhenCallingOnTheFirstIteratorWhenTheListIsEmpty) {//リストが空の際の、先頭イテレータに対して呼び出した際の挙動
	DoublyLinkedList list;
	auto it = list.begin();
	auto adit = ++it;
	ASSERT_DEATH(*adit, ".*");
}
TEST(AdvanceIteratorByOneTowardTheEndOfTheList, BahaviorWhenCalledOnTheTailIterator) {//末尾イテレータに対して呼び出した際の挙動
	DoublyLinkedList list;
	auto it = list.end();
	auto adit = ++it;
	ASSERT_DEATH(*adit, ".*");
}
TEST(AdvanceIteratorByOneTowardTheEndOfTheList, BehaviorWhenCalledWhenThereAreTwoOrMoreElementsInTheList) {//リストに二つ以上の要素がある場合に呼び出した際の挙動
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	list.insert(list.begin(), 2, "name2");
	auto it = list.begin();
	EXPECT_EQ(2, (*it).score);
	auto adit = ++it;
	EXPECT_EQ(1, (*adit).score);
}
TEST(AdvanceIteratorByOneTowardTheEndOfTheList, BehaviorWhenPerformingAPreincrement) {//前置インクリメントを行った際の挙動(++演算子オーバーロード)
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	list.insert(list.begin(), 2, "name2");
	auto it = list.begin();
	EXPECT_EQ(2, (*it).score);
	auto adit = ++it;
	EXPECT_EQ(1, (*adit).score);
}
TEST(AdvanceIteratorByOneTowardTheEndOfTheList, BehaviorWhenPerformingABackincrement) {//後置インクリメントを行った際の挙動(++演算子オーバーロード)
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "a");
	list.insert(list.begin(), 2, "b");
	auto it = list.begin();
	EXPECT_EQ(2, (*it).score);
	it = list.begin();
	auto adit = it++;
	EXPECT_EQ(1, (*adit).score);
}
//後置インクリメント演算子をオーバーロードすることが出来なかったため、スキップ

//iteratorをリストの先頭に向かって一つ進める
TEST(AdvanceIteratorByOneTowardTheTopOfTheList, BehaviorWhenCalledWithNoListReference) {//リストの参照がない状態で呼び出した際の挙動
	DoublyLinkedList::Iterator it = nullptr;
	auto redit  = --it;
	ASSERT_DEATH(*redit, ".*");
}
TEST(AdvanceIteratorByOneTowardTheTopOfTheList, BehaviorWhenCallingOnTheTailIteratorWhenTheListIsEmpty) {//リストが空の際の、末尾イテレータに対して呼び出した際の挙動
	DoublyLinkedList list;
	auto it = list.end();
	auto redit = --it;
	ASSERT_DEATH(*redit, ".*");
}
TEST(AdvanceIteratorByOneTowardTheTopOfTheList, BehaviorWhenCalledOnTheFirstIterator) {//先頭イテレータに対して呼び出した際の挙動
	DoublyLinkedList list;
	auto it = list.begin();
	auto redit = --it;
	ASSERT_DEATH(*redit, ".*");
}
TEST(AdvanceIteratorByOneTowardTheTopOfTheList, BehaviorWhenCalledWhenThereAreTwoOrMoreElementsInTheList) {//リストに二つ以上の要素がある場合に呼び出した際の挙動
	DoublyLinkedList list;
	list.insert(list.end(), 1, "name1");
	list.insert(list.end(), 2, "name2");
	auto it = list.end();
	EXPECT_EQ(2, (*it).score);
	auto redit = --it;
	EXPECT_EQ(1, (*redit).score);
}
TEST(AdvanceIteratorByOneTowardTheTopOfTheList, BehaviorWhenPerformingAPreincrement) {//前置デクリメントを行った際の挙動(--演算子オーバーロード)
	DoublyLinkedList list;
	list.insert(list.end(), 1, "name1");
	list.insert(list.end(), 2, "name2");
	auto it = list.end();
	EXPECT_EQ(2, (*it).score);
	auto adit = --it;
	EXPECT_EQ(1, (*adit).score);
}
TEST(AdvanceIteratorByOneTowardTheTopOfTheList, BehaviorWhenPostfixIncrementIsPerformed) {//後置デクリメントを行った際の挙動(--演算子オーバーロード
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "a");
	list.insert(list.begin(), 2, "b");
	auto it = list.begin();
	EXPECT_EQ(2, (*it).score);
	it = list.begin();
	auto adit = it--;
	EXPECT_EQ(1, (*adit).score);
}
//iteratorのコピーを行う
TEST(MakeACopyOfIterator, CheckThatTheValueAfterCopyConstructIsEqualToTheSource) {//コピーコンストラクト後の値がコピー元と等しいことをチェック
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	auto it = list.begin();
	EXPECT_EQ(1, (*it).score);
	auto end = list.end();
	(*end) = (*it);
	EXPECT_EQ(1, (*end).score);
}

//iteratorの代入を行う。
TEST(PerformIteratorAssignments, ValueIsEqual) {//代入後の値がコピー元と等しいことをチェック
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	auto it = list.begin();
	EXPECT_EQ(1, (*it).score);
	++it;
	auto adit = it;
	(*adit).score = (*it).score;
	EXPECT_EQ(1, (*adit).score);
}

//二つのイテレータが同一のものであるか、比較を行う
TEST(CompareTwoIteratorsToSeeIfTheyAreIdentical, CheckBehaviorWhenComparingTheFirstIteratorWithTheLastIteratorWhenTHeListIsEmpty) {//リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動
	DoublyLinkedList list;
	auto begin = list.begin();
	auto end = list.end();
	bool result = (begin == end);
	EXPECT_TRUE(result);
}
TEST(CompareTwoIteratorsToSeeIfTheyAreIdentical, BehaviorWhenComparingTheSameIterator) {//同一のiteratorを比較した際の挙動
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	auto it = list.begin();
	bool result = (it == it);
	EXPECT_TRUE(result);

}
TEST(CompareTwoIteratorsToSeeIfTheyAreIdentical, BehaviorWhenComparingDifferentIterators) {//異なるイテレータを比較した際の挙動
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	auto begin = list.begin();
	list.insert(list.end(), 2, "name2");
	auto end = list.end();
	bool result = (begin == end);
	EXPECT_FALSE(result);
}
