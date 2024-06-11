//-------------------------------------------------------------------
// 2024 STL		3.5 ~ 6.11
// 
// C++ Object Oriented PL
//		-> polymorphism -> virtual
// 
// STL Generic PL
//		-> template
// 
// class String {
//	RAll
//		special fn;
//		default ctor;
//		dtor;
//		copy ctor;
//		copy operator=;
//		move cotr;
//		move operator=;
//		관찰(메모리);
// }
// 
// Container
// 1. Sequence O(N)
//	array<T, N>
//	vector<T>
//	deque<T>
//	list<T>
//	forward_list<T>
// 2. Associative O(logN)
//	set<k>
//	multiset<k>
//	map<k, v>
//	multimap<k, v> 
// 3. Unordered Associative O(1)
//	unordered_set<k>
//	unordered_multiset<k>
//	unordered_map<k, v>
//	unordered_multimap<k, v>
// 
// Iterator (GoF 23)
// Category5
//	input_iterator_tag
//	output_iterator_tag
//	forward_iterator_tag
//	bidirectional_iterator_tag
//	random_access_iterator_tag
// +
//	contiguous_iterator_tag
//	iterator_traits<반복자>::질문
// 
// class
//	String_iterator;
// class
//	String_Reverse_iterator;
// 
// Algorithm
// f(b, e);
// 1. Non-Modifying Sequence Operation
// 2. Modifying (Mutating)
// 3. Sort and Related Operation
// f(R);
// ㄴ> Constrained Algorithm -> C++20 concept
// ㄴ> Projection, pointer-to-member
// ㄴ> lightweight Object
//		-> Ranges::views
// 
// => Functional PL
//-------------------------------------------------------------------