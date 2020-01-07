#pragma once // изабвляет нас от двойного включения

#include "test_runner.h"
#include "synonyms.h"

using namespace std;

//declaration
void TestAddSynonyms();
void TestCount();
void TestAreSynonyms();
void TestAll();

// defenition
void TestAddSynonyms() {
  { // 1
    Synonyms empty;
    AddSynonyms(empty, "a", "b");
    const Synonyms expected = {
      {"a", {"b"}},
      {"b", {"a"}}
    };
    // assert(empty == expected);
    AssertEqual(empty, expected, "Add to empty");
  }
  { // 2
    Synonyms synonyms = {
      {"a", {"b"}},
      {"b", {"a", "c"}},
      {"c", {"b"}}
    };
    AddSynonyms(synonyms, "a", "c");
    const Synonyms expected = {
      {"a", {"b", "c"}},
      {"b", {"a", "c"}},
      {"c", {"b", "a"}}
    };
    AssertEqual(synonyms, expected, "Add to non-empty");
    assert(synonyms == expected);
  }
}

void TestCount() {
  {
    Synonyms empty;
    // assert(GetSynonymCount(empty, "a") == 0);
    AssertEqual(GetSynonymCount(empty, "a"), 0u, "count for empty");
  }
  {
    Synonyms synonyms = {
      {"a", {"b", "c"}},
      {"b", {"a"}},
      {"c", {"a"}}
    };
    // assert(GetSynonymCount(synonyms, "a") == 2);
    // assert(GetSynonymCount(synonyms, "b") == 1);
    // assert(GetSynonymCount(synonyms, "z") == 0);
    AssertEqual(GetSynonymCount(synonyms, "a"), 2u, "count for a");
    AssertEqual(GetSynonymCount(synonyms, "b"), 1u, "count for b");
    AssertEqual(GetSynonymCount(synonyms, "z"), 0u, "count for z");

  }
}

void TestAreSynonyms() {
  {
    Synonyms empty;
    // assert(!AreSynonyms(empty, "a", "b"));
    // assert(!AreSynonyms(empty, "b", "a"));
    Assert(!AreSynonyms(empty, "a", "b"), "empty a b");
    Assert(!AreSynonyms(empty, "b", "a"), "empty b a");
  }
  {
    Synonyms synonyms = {
      {"a", {"b", "c"}},
      {"b", {"a"}},
      {"c", {"a"}}
    };
    // assert(AreSynonyms(synonyms, "a", "b"));
    // assert(AreSynonyms(synonyms, "a", "c"));
    // assert(AreSynonyms(synonyms, "b", "a"));
    // assert(AreSynonyms(synonyms, "c", "a"));
    // assert(!AreSynonyms(synonyms, "b", "c"));
    // assert(!AreSynonyms(synonyms, "c", "b"));
    Assert(AreSynonyms(synonyms, "a", "b"), "empty a b");
    Assert(AreSynonyms(synonyms, "a", "c"), "empty a c");
    Assert(AreSynonyms(synonyms, "b", "a"), "empty b a");
    Assert(AreSynonyms(synonyms, "c", "a"), "empty c a");
    Assert(!AreSynonyms(synonyms, "b", "c"), "empty b c");
    Assert(!AreSynonyms(synonyms, "c", "b"), "empty c b");
  }
}

void TestAll() {
  TestRunner tr;
  tr.RunTest(TestAreSynonyms, "TestAreSynonyms");
  tr.RunTest(TestCount, "TestCount");
  tr.RunTest(TestAddSynonyms, "TestAddSynonyms");
}
