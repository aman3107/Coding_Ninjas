#include <string>
using namespace std;

template <typename V>
class MapNode
{
public:
  string key;
  V value;
  MapNode *next;
  MapNode(string key, V value)
  {
    this->key = key;
    this->value = value;
    next = NULL;
  }
  ~MapNode()
  {
    delete next;
  }
};

template <typename V>
class ourmap
{
  MapNode<V> **buckets;
  int size;
  int numBuckets;

public:
  ourmap()
  {
    size = 0;
    numBuckets = 5;
    buckets = new MapNode<V> *[numBuckets];
    for (int i = 0; i < numBuckets; i++)
    {
      buckets[i] = NULL;
    }
  }
  ~ourmap()
  {
    for (int i = 0; i < numBuckets; i++)
    {
      delete buckets[i];
    }
    delete[] buckets;
  }

  int getSize()
  {
    return size;
  }

  V getValue(string key)
  {
    int bucketIndex = getBucketIndex(key);
    MapNode<V> *head = buckets[bucketIndex];
    while (head != NULL)
    {
      if (head->key == key)
      {
        return head->value;
      }
      head = head->next;
    }
    return 0;
  }

private:
  int getBucketIndex(string key)
  {
    int hashCode = 0;
    int cureentCoeff = 1;
    for (int i = key.length() - 1; i >= 0; i--)
    {
      hashCode += key[i] * cureentCoeff;
      hashCode = hashCode % numBuckets;
      cureentCoeff *= 37;
      cureentCoeff = cureentCoeff % numBuckets;
    }
    return hashCode % numBuckets;
  }

  void rehash()
  {
    MapNode<V> **temp = buckets;
    buckets = new MapNode<V> *[2 * numBuckets];
    for (int i = 0; i < 2 * numBuckets; i++)
    {
      buckets[i] = NULL;
    }
    int oldBucketCount = numBuckets;
    numBuckets = 2 * numBuckets;
    size = 0;

    for (int i = 0; i < oldBucketCount; i++)
    {
      MapNode<V> *head = temp[i];
      while (head != NULL)
      {
        string key = head->key;
        V value = head->value;
        insert(key, value);
        head = head->next;
      }
    }
    for (int i = 0; i < oldBucketCount; i++)
    {
      MapNode<V> *head = temp[i];
      delete head;
    }
    delete[] temp;
  }

public:
  void insert(string key, V value)
  {
    int bucketIndex = getBucketIndex(key);
    MapNode<V> *head = buckets[bucketIndex];
    while (head != NULL)
    {
      if (head->key == key)
      {
        head->value = value;
      }
      head = head->next;
    }
    head = buckets[bucketIndex];
    MapNode<V> *node = new MapNode<V>(key, value);
    node->next = head;
    buckets[bucketIndex] = node;
    size++;
    double loadFactor = (1.0 * size) / numBuckets;
    if (loadFactor > 0.7)
    {
      rehash();
    }
  }

  double getLoadFactor()
  {
    return (1.0 * size) / numBuckets;
  }

  V removeKey(string key)
  {
    int bucketIndex = getBucketIndex(key);
    MapNode<V> *head = buckets[bucketIndex];
    MapNode<V> *prev = NULL;
    while (head != NULL)
    {
      if (head->key == key)
      {
        if (prev == NULL)
        {
          buckets[bucketIndex] = head->next;
        }
        else
        {
          prev->next = head->next;
        }
        V value = head->value;
        head->next = NULL;
        delete head;
        size--;
        return value;
      }
      prev = head;
      head = head->next;
    }
    return 0;
  }
};