import ctypes

lib = ctypes.CDLL('./my_lib.so')

_filter = lib.filter
_filter.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int))
_filter.restype = ctypes.c_int

_shift = lib.cycle_left_shift
_shift.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.c_int)
_shift.restype = ctypes.c_int

def filter_1(nums):
    src_len = len(nums)
    src = (ctypes.c_int * src_len)(*nums)
    dst_len = ctypes.c_int(0)

    rc = _filter(src, src_len, None, dst_len)
    if rc:
        dst = (ctypes.c_int * dst_len.value)()
        rc = _filter(src, src_len, dst, dst_len)
        return rc, list(dst)
    else:
        return rc, list()
    
def filter_2(nums):
    src_len = len(nums)
    src = (ctypes.c_int * src_len)(*nums)
    dst_len = ctypes.c_int(src_len)
    dst = (ctypes.c_int * src_len)()

    rc = _filter(src, src_len, dst, dst_len)
    
    return rc, list(dst[:dst_len.value])

def shift(nums, col):
    size = len(nums)
    arr = (ctypes.c_int * size)(*nums)
    
    rc = _shift(arr, size, col)
    return rc, list(arr)