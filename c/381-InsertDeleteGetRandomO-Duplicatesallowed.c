typedef char bool;
#define true 1
#define false 0

typedef struct {
	int *arr;
	int size;
	int len;
} RandomizedCollection;

#define RANDOMIZEDCOLLECTION_INITSIZE 8

/** Initialize your data structure here. */
RandomizedCollection* randomizedCollectionCreate() {
	RandomizedCollection* collection = malloc(sizeof(RandomizedCollection));
	if (collection==NULL)
		return NULL;

	collection->arr = malloc(sizeof(int)*RANDOMIZEDCOLLECTION_INITSIZE);
	collection->size = RANDOMIZEDCOLLECTION_INITSIZE;
	collection->len = 0;

	return collection;
}

/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
bool randomizedCollectionInsert(RandomizedCollection* obj, int val) {
	bool ret = true;
	int lo=0, hi=obj->len-1;

	if (obj->len + 1 >= obj->size) {
		int* p = realloc(obj->arr, obj->size * 2 * sizeof(int));
		if (p == NULL)
			return false;
		obj->arr = p;
		obj->size = obj->size * 2;
	}

	int idx = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (obj->arr[mid] < val)
			lo = mid + 1;
		else if (obj->arr[mid] > val)
			hi = mid - 1;
		else {
			idx = mid;
			ret = false;
			break;
		}
	}

	if (idx == -1)
		idx = lo;
	int i;
	for (i=obj->len; i-1>=idx; i--)
		obj->arr[i] = obj->arr[i-1];
	obj->arr[idx] = val;
	obj->len ++;

	return ret;
}

/** Removes a value from the collection. Returns true if the collection contained the specified element. */
bool randomizedCollectionRemove(RandomizedCollection* obj, int val) {
	int lo=0, hi=obj->len-1;

	int idx = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (obj->arr[mid] > val)
			hi = mid - 1;
		else if (obj->arr[mid] < val)
			lo = mid + 1;
		else {
			idx = mid;
			break;
		}
	}

	if (idx == -1)
		return false;

	int i;
	for (i=idx; i+1<obj->len; i++) {
		obj->arr[i] = obj->arr[i+1];
	}
	obj->len--;

	return true;
}

/** Get a random element from the collection. */
int randomizedCollectionGetRandom(RandomizedCollection* obj) {
	if (obj->len == 0)
		return 0;

	int r = rand() % obj->len;
	return obj->arr[r];
}

void randomizedCollectionFree(RandomizedCollection* obj) {
	if (obj != NULL) {
		if (obj->arr != NULL)
			free (obj->arr);
		free (obj);
	}
}

/**
 * Your RandomizedCollection struct will be instantiated and called as such:
 * struct RandomizedCollection* obj = randomizedCollectionCreate();
 * bool param_1 = randomizedCollectionInsert(obj, val);
 * bool param_2 = randomizedCollectionRemove(obj, val);
 * int param_3 = randomizedCollectionGetRandom(obj);
 * randomizedCollectionFree(obj);
 */
