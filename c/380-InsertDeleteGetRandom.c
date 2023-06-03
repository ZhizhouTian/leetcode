typedef char bool;

#define true 1
#define false 0

typedef struct {
	int* arr;
	int size;
	int len;
} RandomizedSet;

#define RANDOMIZEDSET_INITSIZE 8
/** Initialize your data structure here. */
RandomizedSet* randomizedSetCreate() {
	RandomizedSet* set = malloc(sizeof(RandomizedSet));
	if (set == NULL)
		return NULL;

	set->arr = malloc(sizeof(int) * RANDOMIZEDSET_INITSIZE);
	if (set->arr == NULL)
		goto no_mem;

	set->size = RANDOMIZEDSET_INITSIZE;
	set->len = 0;

	return set;
no_mem:
	if (set != NULL)
		free(set);
	return NULL;
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool randomizedSetInsert(RandomizedSet* obj, int val) {
	int lo=0, hi=obj->len-1;
	bool ret = true;

	if (obj->len + 1 >= obj->size) {
		int* p = realloc(obj->arr, sizeof(int)*obj->size*2);
		if (p == NULL)
			return false;
		obj->arr = p;
		obj->size = obj->size * 2;
	}

	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if (obj->arr[mid] > val)
			hi = mid -1;
		else if (obj->arr[mid] < val)
			lo = mid + 1;
		else
			return false;
	}

	int idx = lo;

	int i;
	for (i=obj->len; i-1>=lo; i--)
		obj->arr[i] = obj->arr[i-1];
	obj->arr[idx] = val;
	obj->len = obj->len + 1;
	return ret;
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
bool randomizedSetRemove(RandomizedSet* obj, int val) {
	int lo=0, hi=obj->len-1;
	bool ret = false;

	int idx = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (obj->arr[mid] > val)
			hi = mid -1;
		else if (obj->arr[mid] < val)
			lo = mid + 1;
		else {
			ret = true;
			idx = mid;
			break;
		}
	}

	if (idx == -1)
		return false;

	int i;
	for (i=idx; i+1<=obj->len-1; i++)
		obj->arr[i] = obj->arr[i+1];
	obj->len = obj->len - 1;
	return true;
}

/** Get a random element from the set. */
int randomizedSetGetRandom(RandomizedSet* obj) {
	if (obj->len == 0)
		return -1;
	else if(obj->len == 1)
		return obj->arr[0];

	int r = rand() % obj->len;
	return obj->arr[r];
}

void randomizedSetFree(RandomizedSet* obj) {
	if (obj != NULL) {
		if (obj->arr != NULL)
			free (obj->arr);
		free(obj);
	}
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * struct RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);
 * bool param_2 = randomizedSetRemove(obj, val);
 * int param_3 = randomizedSetGetRandom(obj);
 * randomizedSetFree(obj);
 */
