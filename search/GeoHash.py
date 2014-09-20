def GeoHash(lat, lng):
    max_lat = 180
    min_lat = -180
    max_lng = 90
    min_lng = -90
    if not (min_lat<=lat<=max_lat) or not (min_lng<=lng<=max_lng):
        return -1
    ret = ""
    for i in xrange(26):
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
