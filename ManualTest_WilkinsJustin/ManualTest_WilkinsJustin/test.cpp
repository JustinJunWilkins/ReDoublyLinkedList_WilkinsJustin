#include "pch.h"
#include "class.h"
#define TT_TEST_GET_DATA_NUM_WHEN_CONST
#define TT_TEST_REFERENCE_DATA_CONST
#define TT_TEST_COPY_IT_CONSTIT
#define TT_TEST_ASSIGNMENT_IT_CONSTIT
TEST(GetDataNumTest, DataIsConst) {
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
	const DoublyLinkedList list;
	EXPECT_EQ(0, list.getSize());
#endif TT_TEST_GET_DATA_NUM_WHEN_CONST
	SUCCEED();
}
TEST(DataInsertion, DataIsNonConst) {
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.begin();
	list.Constinsert(list.begin(),1, "name1");
#endif TT_TEST_GET_DATA_NUM_WHEN_CONST
	SUCCEED();
}
TEST(DeletionOfData, DataIsNonConst) {
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.begin();
	list.Constremove(it);
#endif TT_TEST_GET_DATA_NUM_WHEN_CONST
	SUCCEED();
}
TEST(ObtainingTheFirstIterator, NotGetIterator) {
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.begin();
	(*it).score = 1;
#endif TT_TEST_GET_DATA_NUM_WHEN_CONST
	SUCCEED();
}
TEST(ObtainingTheFirstIterator, DataIsConst) {
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
	DoublyLinkedList list;
	DoublyLinkedList::Iterator::ConstIterator it = list.begin();
	list.Constinsert(it, 1, "name1");
#endif TT_TEST_GET_DATA_NUM_WHEN_CONST
	SUCCEED();
}
TEST(ObtainingTheLastIterator, NotGetIterator) {
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.end();
	(*it).score = 1;
#endif TT_TEST_GET_DATA_NUM_WHEN_CONST
	SUCCEED();
}
TEST(ObtainingTheFirstIterator, DataIsConst) {
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
	DoublyLinkedList list;
	DoublyLinkedList::Iterator::ConstIterator it = list.end();
	list.Constinsert(it, 1, "name1");
#endif TT_TEST_GET_DATA_NUM_WHEN_CONST
	SUCCEED();
}
TEST(GetTheElementPointedToByTheIterator, NotReference) {
#if defined TT_TEST_REFERENCE_DATA_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator constit = list.begin();
	list.Constinsert(constit, 1, "name1");
	DoublyLinkedList::Iterator it = list.begin();
	(*it).score = (*constit).score;
#endif  TT_TEST_REFERENCE_DATA_CONST
}
TEST(MakeACopyOfIterator, CheckToSeeIfACopyOfTheIteratorIsCreatedFromConstIterator) {//ConstIteratorから、Iteratorのコピーが作成されないかチェック
#if defined TT_TEST_COPY_IT_CONSTIT
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator constit = list.begin();
	list.Constinsert(constit, 1, "name1");
	DoublyLinkedList::Iterator it = list.begin();
	*it = *constit;
#endif TT_TEST_COPY_IT_CONSTIT
}
TEST(PerformIteratorAssignments, ItAsToConstit) {
#if defined TT_TEST_ASSIGNMENT_IT_CONSTIT
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.begin();
	DoublyLinkedList::ConstIterator const constit = list.begin();
	list.insert(it, 1, "name1");
	*constit.score = (*it).score;
#endif TT_TEST_ASSIGNMENT_IT_CONSTIT
}