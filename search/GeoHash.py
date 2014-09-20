MAX_LAT = 180
MIN_LAT = -180
MAX_LNG = 90
MIN_LNG = -90


def GeoHash(lat, lng, times=26):
    if not (MIN_LAT<=lat<=MAX_LAT and MIN_LNG<=lng<=MAX_LNG) or times<=0:
        return -1
    max_lat = MAX_LAT
    min_lat = MIN_LAT
    max_lng = MAX_LNG
    min_lng = MIN_LNG
    ret = ""
    for i in xrange(times):
        if lat < (max_lat+min_lat)/2.0:
            second = '0'
            max_lat = (max_lat+min_lat)/2.0
        else:
            second = '1'
            min_lat = (max_lat+min_lat)/2.0
        if lng < (max_lng+min_lng)/2.0:
            first = '0'
            max_lng = (max_lng+min_lng)/2.0
        else:
            first = '1'
            min_lng = (max_lng+min_lng)/2.0
        ret = ret+first+second
    return ret

if __name__ == "__main__":
    point = (58, -29)
    hash_val = GeoHash(point[0], point[1])
    print hash_val

    point = (-58, 29)
    hash_val = GeoHash(point[0], point[1])
    print hash_val
    print

    print len(hash_val)
    print

    point = (-58, 29)
    hash_val = GeoHash(point[0], point[1], 2)
    print hash_val
    print len(hash_val)
    print 
