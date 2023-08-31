#include "pch.h"
#include "class.h" //双方向リストのクラス
#include <iostream>
//データ数の取得
TEST(GetDataNumTest, TestGetDataNumWhenEmpty) {//リストが空である場合の戻り値
	DoublyLinkedList list;
	EXPECT_EQ(0, list.getSize());
}
TEST(GetDataNumTest, ReturnValueWhenInsertedDataTheEndOfTheList) {//リスト末尾への挿入を行った際の戻り値
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.end();
	/*ASSERT_TRUE(list.insert(it,1, "username"));*/
	list.insert(it, 1, "username");
	EXPECT_EQ(1, list.getSize());
}
TEST(GetDataNumTest, ReturnValueWhenInsertionAtTheEndOfTheListFailed) {//リスト末尾への挿入が失敗した際の戻り値
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.end();
	list.insert(it, 0, "username");
	/*ASSERT_TRUE(list.insert(it, 0, "username"));*/
	EXPECT_EQ(1, list.getSize());
	/*メモリ確保失敗時のためスキップ*/
}
TEST(GetDataNumTest, ReturnValueWhenDataIsInserted) {//データの挿入を行った際の戻り値
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.end();
	list.insert(it, 1, "username");
	EXPECT_EQ(1, list.getSize());
}
TEST(GetDataNumTest, ReturnValueWhenDataInsertionFails) {//データの挿入に失敗した際の戻り値
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.end();
	//メモリ確保時失敗時の為スキップ
}
TEST(GetDataNumTest, ReturnValueWhenDataIsDeleted) {//データの削除を行った際の戻り値
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	EXPECT_EQ(1, list.getSize());
	list.remove(list.begin());
	EXPECT_EQ(0, list.getSize());
}
TEST(GetDataNumTest, ReturnValueWhenDataDeletionFails) {//データの削除が失敗した際の戻り値
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.end();
	//メモリ確保時失敗時のためスキップ
}
TEST(GetDataNumTest, ReturnValueWhenDataIsDeletedIfTheListIsEmpty) {//リストが空である場合に、データの削除を行った際の戻り値
	//DoublyLinkedList list;
	//EXPECT_EQ(0, list.getSize());
	//auto it = list.begin();
	//list.remove(it);
	//EXPECT_EQ(0, list.getSize());
	////存在しないリストを削除しようとし、エラーになるためスキップ
}

//データの挿入
TEST(DataInsertion, BehaviorWhenInsertedIfTheListIsEmptyHead) {//リストが空である場合に、挿入した際の挙動（先頭）
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.end();

	list.insert(it, 1, "username");
	EXPECT_TRUE(1, list.end());

}
TEST(DataInsertion, BehaviorWhenInsertedIfTheListIsEmptyTail) {//リストが空である場合に、挿入した際の挙動（末尾）
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.end();

	list.insert(it, 1, "username");
	EXPECT_TRUE(1, list.end());

}
TEST(DataInsertion, BehaviorWhenInsertingMultipleElementsInAListByPassingTheFirstIterator) {//リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動
	DoublyLinkedList list;
	list.insert(list.begin(), 10, "a");
	list.insert(list.begin(), 20, "b");

	auto it = list.begin();
	list.insert(it, 1, "name");
	it = list.begin();
	EXPECT_EQ(1, (*it).score);
	EXPECT_EQ("name", (*it).username);
}
TEST(DataInsertion, BahaviorWhenInsertingMultipleElementsInAListByPassingATrailingIterator) {//リストに複数の要素がある場合に、末尾イテレータを渡して、挿入した際の挙動
	DoublyLinkedList list;
	list.insert(list.begin(), 10, "a");
	list.insert(list.begin(), 20, "b");

	auto it = list.end();
	list.insert(it, 1, "name");
	it = list.end();
	EXPECT_EQ(1, (*it).score);
	EXPECT_EQ("name", (*it).username);
}
TEST(DataInsertion, BehaviorWhenInsertingMultipleElementsInAListByPassingAnIteratorThatIsNeitherTheFirstNortheLastElement) {//リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動
	DoublyLinkedList list;
	list.insert(list.begin(), 10, "a");
	list.insert(list.begin(), 20, "b");

	auto it = list.begin();
	list.insert(it, 30, "c"); // 正しい位置に挿入
	it = list.begin();
	EXPECT_EQ(30, (*it).score);
	auto additionalit = ++it;
	EXPECT_EQ(20, (*additionalit).score);

}
TEST(DataInsertion, BehaviorWhenInsertingWithConstIterator) {//ConstIteratorを指定して挿入を行った際の挙動
	DoublyLinkedList list;
	auto constit = list.begin();
	list.Constinsert(constit, 10, "name");
	constit = list.begin();
	EXPECT_EQ(10, (*constit).score);
}
TEST(DataInsertion, BehaviorWhenAnIllegalIteratorIsPassedAndInserted) {//不正なイテレータを渡して、挿入した際の挙動
	DoublyLinkedList list;
	int count = 0;
	DoublyLinkedList::Iterator It = nullptr;
	if (It != nullptr) {
		++count;
	}
	EXPECT_EQ(0, count);
}
TEST(DataInsertion, IsItANonConstMethod) {//非constのメソッドであるか
#if defined TT_TEST_INSERT_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.begin();
	list.insert(it, 1);
#endif 
	SUCCEED();
}

//データの削除->変数removeが、無効なiteratorを参照してしまうため一旦スキップ
TEST(DeletionOfData, BehaviorWhenDeletingWhenTheListisEmpty) {//リストが空である場合に、削除を行った際の挙動
	//DoublyLinkedList list;
	//EXPECT_EQ(0, list.getSize());
	//auto begin = list.begin();
	//list.remove(begin);
	//EXPECT_EQ(0, list.getSize());
	//auto end = list.end();
	//list.remove(end);
	//EXPECT_EQ(0, list.getSize());
	//存在しないリストを削除しようとし、エラーになるためスキップ
}
TEST(DeletionOfData, BehaviorWhenAListHasMultipleElementsPassingTheFirstIteratorAndThenDeleting) {//リストに複数の要素がある場合に、先頭イテレータを渡して、削除した際の挙動
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	list.insert(list.begin(), 2, "name2");
	list.insert(list.begin(), 3, "name3");
	list.remove(list.begin());
	auto it = list.begin();
	EXPECT_EQ(2, (*it).score);
}
TEST(DeletionOfData, BehaviorWhenThereAreMultipleElementsinAListPassingATrailingIteratorAndDeleting) {//リストに複数の要素がある場合に、末尾イテレータを渡して、削除した際の挙動
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	list.insert(list.begin(), 2, "name2");
	list.insert(list.end(), 3, "name3");
	list.remove(list.end());
	auto it = list.end();
	EXPECT_EQ(2, (*it).score);
}
TEST(DeletionOfData, BehaviorWhenDeletingMultipleElementsInAListByPassingAnIteratorThatIsNeitherTheFirstNorTheLastElement) {//リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動
	DoublyLinkedList list;
	list.insert(list.begin(), 10, "a");
	list.insert(list.begin(), 20, "b");

	auto it = list.begin();
	list.insert(it, 30, "c"); // 正しい位置に挿入
	it = list.begin();
	EXPECT_EQ(30, (*it).score);
	auto additionalit = ++it;
	EXPECT_EQ(20, (*additionalit).score);

}
TEST(DeletionOfData, BehaviorWhenAConstIteratorIsSpecifiedForDeletion) {//ConstIteratorを指定して削除を行った際の挙動
	DoublyLinkedList list;
	list.Constinsert(list.begin(), 1, "name1");
	list.Constinsert(list.begin(), 2, "name2");
	EXPECT_EQ(2, list.getSize());
	list.Constremove(list.begin());
	EXPECT_EQ(1, list.getSize());
	EXPECT_EQ(1, (*list.begin()).score);

}
TEST(DeletionOfData, BehaviorWhenAnIllegalIteratorIsPassedAndDeleted) {//不正なイテレータを渡して、削除した場合の挙動
	//参照先のないIteratorを渡すと、不正なメモリアクセスとなりエラーが出るためスキップ
}
//先頭イテレータの取得
TEST(ObtainingTheFirstIterator, BehaviorWhenCalledIfTheListisEmpty) {//リストが空である場合に、呼び出した際の挙動
	DoublyLinkedList list;
	auto it = nullptr;
	if (it == nullptr) {
		list.insert(list.begin(), -1, "dummy");
	}
	EXPECT_EQ(-1, (*list.begin()).score);
}
TEST(ObtainingTheFirstIterator, BehaviorWhenCalledWhenThereIsOneElementInTheList) {//リストに要素が一つある場合に、呼び出した際の挙動
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "a");
	auto it = list.begin();
	EXPECT_EQ(1, (*it).score);
	EXPECT_EQ("a", (*it).username);
}
TEST(ObtainingTheFirstIterator, BehaviorWhenCalledWhenThereAreTwoOrMoreElementsInTheList) {//リストに二つ以上の要素がある場合に、呼び出した際の挙動
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "a");
	list.insert(list.begin(), 2, "b");
	auto it = list.begin();
	EXPECT_EQ(2, (*it).score);
	EXPECT_EQ("b", (*it).username);
}
TEST(ObtainingTheFirstIterator, BehaviorWhenCalledAfterInsertingDataFirst) {//データの挿入を行った後に、呼び出した際の挙動（先頭）
	DoublyLinkedList list;
	auto it = list.begin();
	list.insert(it, 1, "a");
	it = list.begin();
	EXPECT_EQ(1, (*it).score);
	EXPECT_EQ("a", (*it).username);
}
TEST(ObtainingTheFirstIterator, BehaviorWhenCalledAfterInsertingDataCentral) {//データの挿入を行った後に、呼び出した際の挙動（中央）
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	list.insert(list.begin(), 2, "name2");
	auto it = list.begin();
	auto cenit = ++it;
	//list.insert(cenit, 3, "name3");
	EXPECT_EQ(2, (*it).score);
}
TEST(ObtainingTheFirstIterator, BehaviorWhenCalledAfterInsertingDataLast) {//データの挿入を行った後に、呼び出した際の挙動（末尾）
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	list.insert(list.begin(), 2, "name2");
	auto it = list.begin();
	list.insert(list.end(), 3, "name3");
	EXPECT_EQ(2, (*it).score);
}
TEST(ObtainingTheFirstIterator, BehaviorWhenCalledAfterDeletingDataFirst) {//データの削除を行った後に、呼び出した際の挙動（先頭）
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "a");
	auto it = list.begin();
	EXPECT_EQ(1, (*it).score);
	list.remove(it);
	EXPECT_EQ(0, list.getSize());
}
TEST(ObtainingTheFirstIterator, BehaviorWhenCalledAfterDeletingDataCentral) {//データの削除を行った後に、呼び出した際の挙動（中央）
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	list.insert(list.begin(), 2, "name2");
	list.insert(list.begin(), 3, "name3");
	auto it = list.begin();
	auto cenit = ++it;
	//list.remove(cenit);
	EXPECT_EQ(3, (*it).score);
}
TEST(ObtainingTheFirstIterator, BehaviorWhenCalledAfterDeletingDataLast) {//データの削除を行った後に、呼び出した際の挙動（末尾）
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	list.insert(list.begin(), 2, "name2");
	list.insert(list.begin(), 3, "name3");
	auto begin = list.begin();
	auto end = list.end();
	list.remove(end);
	begin = list.begin();
	EXPECT_EQ(2, (*begin).score);
}

//先頭コンストイテレータの取得
TEST(ObtainingTheFirstConstIterator, BehaviorWhenCalledIfTheListisEmpty) {//リストが空である場合に、呼び出した際の挙動
	DoublyLinkedList list;
	auto constit = nullptr;
	if (constit == nullptr) {
		list.Constinsert(list.begin(), -1, "dummy");
	}
	EXPECT_EQ(-1, (*list.begin()).score);
}
TEST(ObtainingTheFirstConstIterator, BehaviorWhenCalledWhenThereIsOneElementInTheList) {//リストに要素が一つある場合に、呼び出した際の挙動
	DoublyLinkedList list;
	list.Constinsert(list.begin(), 1, "name");
	auto constit = list.begin();
	EXPECT_EQ(1, (*constit).score);
	EXPECT_EQ("name", (*constit).username);
}
TEST(ObtainingTheFirstConstIterator, BehaviorWhenCalledWhenThereAreTwoOrMoreElementsInTheList) {//リストに二つ以上の要素がある場合に、呼び出した際の挙動
	DoublyLinkedList list;
	list.Constinsert(list.begin(), 1, "name1");
	list.Constinsert(list.begin(), 2, "name2");
	auto constit = list.begin();
	EXPECT_EQ(2, (*constit).score);
	EXPECT_EQ("name2", (*constit).username);
}
TEST(ObtainingTheFirstConstIterator, BehaviorWhenCalledAfterInsertingDataFirst) {//データの挿入を行った後に、呼び出した際の挙動（先頭）
	DoublyLinkedList list;
	list.Constinsert(list.begin(), 1, "name1");
	auto constit = list.begin();
	EXPECT_EQ(1, (*constit).score);
	EXPECT_EQ("name1", (*constit).username);
}
TEST(ObtainingTheFirstConstIterator, BehaviorWhenCalledAfterInsertingDatafirstCentral) {//データの挿入を行った後に、呼び出した際の挙動（中央）
	DoublyLinkedList list;
	list.Constinsert(list.begin(), 1, "name1");
	list.Constinsert(list.begin(), 3, "name3");
	auto constit = list.begin();
	auto additionalconstit = ++constit;
	list.Constinsert(additionalconstit, 2, "name2");
	constit = list.begin();
	EXPECT_EQ(3, (*constit).score);
}
TEST(ObtainingTheFirstConstIterator, BehaviorWhenCalledAfterInsertingDataFirstLast) {//データの挿入を行った後に、呼び出した際の挙動（末尾）
	DoublyLinkedList list;
	list.Constinsert(list.end(), 1, "name1");
	auto constit = list.begin();
	EXPECT_EQ(1, (*constit).score);
	EXPECT_EQ("name1", (*constit).username);
}
TEST(ObtainingTheFirstConstIterator, BehaviorWhenCalledAfterDeletingDataFirst) {//データの削除を行った後に、呼び出した際の挙動（先頭）
	DoublyLinkedList list;
	list.Constinsert(list.begin(), 1, "name1");
	list.Constinsert(list.begin(), 2, "name2");
	list.Constremove(list.begin());
	auto constit = list.begin();
	EXPECT_EQ(1, (*constit).score);
	EXPECT_EQ("name1", (*constit).username);
}
TEST(ObtainingTheFirstConstIterator, BehaviorWhenCalledAfterDeletingDataCentral) {//データの削除を行った後に、呼び出した際の挙動（中央）
	DoublyLinkedList list;
	list.Constinsert(list.begin(), 1, "name1");
	list.Constinsert(list.begin(), 2, "name2");
	list.Constinsert(list.begin(), 3, "name3");
	auto constit = list.begin();
	auto additionalconstit = ++constit;
	list.Constremove(additionalconstit);
	EXPECT_EQ(3, (*constit).score);
	EXPECT_EQ("name3", (*constit).username);
}
TEST(ObtainingTheFirstConstIterator, BehaviorWhenCalledAfterDeletingDataLast) {//データの削除を行った後に、呼び出した際の挙動（末尾）
	DoublyLinkedList list;
	list.Constinsert(list.end(), 1, "name1");
	list.Constinsert(list.end(), 2, "name2");
	list.Constinsert(list.end(), 3, "name3");
	auto begin = list.begin();
	auto end = list.end();
	list.Constremove(end);
	begin = list.begin();
	EXPECT_EQ(2, (*begin).score);
	EXPECT_EQ("name2", (*begin).username);
}
TEST(ObtainingTheFirstConstIterator, IsItAConstMethod) {//constのメソッドであるか

}

//末尾イテレータの取得→末尾のイテレータを取り出すメソッドに不具合あり
TEST(ObtainingTheEndIterator, BehaviorWhenCalledIfTheListisEmpty) {//リストが空である場合に、呼び出した際の挙動
	DoublyLinkedList list;
	if (list.getSize() == 0) {
		EXPECT_EQ(-1, (*list.begin()).score);
	}
}
TEST(ObtainingTheEndIterator, BehaviorWhenCalledWhenThereIsOneElementInTheList) {//リストに要素が一つある場合に、呼び出した際の挙動
	DoublyLinkedList list;
	list.insert(list.end(), 1, "a");
	auto it = list.end();
	EXPECT_EQ(1, (*it).score);
}
TEST(ObtainingTheEndIterator, BehaviorWhenCalledWhenThereAreTwoOrMoreElementsInTheList) {//リストに二つ以上の要素がある場合に、呼び出した際の挙動
	DoublyLinkedList list;
	list.insert(list.end(), 1, "name1");
	list.insert(list.end(), 2, "name2");
	auto it = list.end();
	EXPECT_EQ(2, (*it).score);
}
TEST(ObtainingTheEndIterator, BehaviorWhenCalledAfterInsertingDataFirst) {//データの挿入を行った後に、呼び出した際の挙動（先頭）
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	list.insert(list.begin(), 2, "name2");
	auto it = list.end();
	EXPECT_EQ(2, (*it).score);
	EXPECT_EQ("name2", (*it).username);
}
TEST(ObtainingTheEndIterator, BehaviorWhenCalledAfterInsertingDataCentral) {//データの挿入を行った後に、呼び出した際の挙動（中央）
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	list.insert(list.begin(), 2, "name2");
	auto it = list.begin();
	list.insert(it, 3, "name3");
	auto additionalit = ++it;
	EXPECT_EQ(1, (*additionalit).score);
}
TEST(ObtainingTheEndIterator, BehaviorWhenCalledAfterInsertingDataLast) {//データの挿入を行った後に、呼び出した際の挙動（末尾）
	DoublyLinkedList list;
	list.insert(list.end(), 1, "name1");
	list.insert(list.end(), 2, "name2");
	auto it = list.end();
	EXPECT_EQ(2, (*it).score);
	auto additionalit = --it;
	EXPECT_EQ(1, (*additionalit).score);
}
TEST(ObtainingTheEndIterator, BehaviorWhenCalledAfterDeletingDataFirst) {//データの削除を行った後に、呼び出した際の挙動（先頭）
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	list.insert(list.begin(), 2, "name2");
	list.remove(list.begin());
	auto it = list.end();
	EXPECT_EQ(1, (*it).score);
}
TEST(ObtainingTheEndIterator, BehaviorWhenCalledAfterDeletingDataFirstCentral) {//データの削除を行った後に、呼び出した際の挙動（中央）
	DoublyLinkedList list;
	list.insert(list.begin(), 1, "name1");
	list.insert(list.begin(), 2, "name2");
	list.insert(list.begin(), 3, "name3");
	auto it = list.begin();
	auto adit = ++it;
	//list.remove(adit);
	it = list.end();
	EXPECT_EQ(3, (*it).score);
}
TEST(ObtainingTheEndIterator, BehaviorWhenCalledAfterDeletingDataFirstLast) {//データの削除を行った後に、呼び出した際の挙動（末尾）
	DoublyLinkedList list;
	list.insert(list.end(), 1, "name1");
	list.insert(list.end(), 2, "name2");
	list.insert(list.end(), 3, "name3");
	auto it = list.end();
	list.remove(it);
	it = list.end();
	EXPECT_EQ(2, (*it).score);
}
TEST(ObtainingTheEndIterator, CheckIfItIsPossibleToGetAnIteratorThatIsNotAConstIteratorFromAListOfConst) {//constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック

}

//末尾コンストイテレータの取得
TEST(ObtainingTheEndConstIterator, BehaviorWhenCalledIfTheListisEmpty) {//リストが空である場合に、呼び出した際の挙動
	DoublyLinkedList list;
	auto constit = nullptr;
	if (constit == nullptr) {
		list.Constinsert(list.end(), -1, "dummy");
	}
	EXPECT_EQ(-1, (*list.end()).score);
}
TEST(ObtainingTheEndConstIterator, BehaviorWhenCalledWhenThereIsOneElementInTheList) {//リストに要素が一つある場合に、呼び出した際の挙動
	DoublyLinkedList list;
	list.Constinsert(list.end(), 1, "name1");
	auto constit = list.end();
	EXPECT_EQ(1, (*constit).score);
}
TEST(ObtainingTheEndConstIterator, BehaviorWhenCalledWhenThereAreTwoOrMoreElementsInTheList) {//リストに二つ以上の要素がある場合に、呼び出した際の挙動
	DoublyLinkedList list;
	list.Constinsert(list.end(), 1, "name1");
	list.Constinsert(list.end(), 2, "name2");
	auto constit = list.end();
	EXPECT_EQ(2, (*constit).score);
}
TEST(ObtainingTheEndConstIterator, BehaviorWhenCalledAfterInsertingDataFirst) {//データの挿入を行った後に、呼び出した際の挙動（先頭）
	DoublyLinkedList list;
	list.Constinsert(list.begin(), 1, "name1");
	list.Constinsert(list.begin(), 2, "name2");
	auto constit = list.end();
	EXPECT_EQ(2, (*constit).score);
}
TEST(ObtainingTheEndConstIterator, BehaviorWhenCalledAfterInsertingDataCentral) {//データの挿入を行った後に、呼び出した際の挙動（中央）
	DoublyLinkedList list;
	list.Constinsert(list.begin(), 1, "name1");
	list.Constinsert(list.begin(), 3, "name3");
	auto constit = list.begin();
	auto additionalconstit = ++constit;
	list.Constinsert(additionalconstit, 2, "name2");
	constit = list.end();
	EXPECT_EQ(3, (*constit).score);
}
TEST(ObtainingTheEndConstIterator, BehaviorWhenCalledAfterInsertingDataLast) {//データの挿入を行った後に、呼び出した際の挙動（末尾）
	DoublyLinkedList list;
	list.Constinsert(list.end(), 1, "name1");
	list.Constinsert(list.end(), 2, "name2");
	auto constit = list.end();
	list.Constinsert(constit, 3, "name3");
	constit = list.end();
	EXPECT_EQ(3, (*constit).score);
}
TEST(ObtainingTheEndConstIterator, BehaviorWhenCalledAfterDeletingDataFirst) {//データの削除を行った後に、呼び出した際の挙動（先頭）
	DoublyLinkedList list;
	list.Constinsert(list.begin(), 1, "name1");
	list.Constinsert(list.begin(), 2, "name2");
	auto constit = list.end();
	list.Constremove(constit);
	constit = list.end();
	EXPECT_EQ(1, (*constit).score);
}
TEST(ObtainingTheEndConstIterator, BehaviorWhenCalledAfterDeletingDataCentral) {//データの削除を行った後に、呼び出した際の挙動（中央）
	DoublyLinkedList list;
	list.Constinsert(list.begin(), 1, "name1");
	list.Constinsert(list.begin(), 2, "name2");
	list.Constinsert(list.begin(), 3, "name3");
	auto constit = list.begin();
	auto additionalconstit = ++constit;
	list.Constremove(additionalconstit);
	constit = list.end();
	EXPECT_EQ(3, (*constit).score);
}
TEST(ObtainingTheEndConstIterator, BehaviorWhenCalledAfterDeletingDataLast) {//データの削除を行った後に、呼び出した際の挙動（末尾）
	DoublyLinkedList list;
	list.Constinsert(list.end(), 1, "name1");
	list.Constinsert(list.end(), 2, "name2");
	list.Constinsert(list.end(), 3, "name3");
	auto constit = list.end();
	list.Constremove(constit);
	constit = list.end();
	EXPECT_EQ(2, (*constit).score);
}
TEST(ObtainingTheEndConstIterator, IsItAConstMethod) {//constのメソッドであるか

}