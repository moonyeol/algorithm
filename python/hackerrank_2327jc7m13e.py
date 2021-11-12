#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'validateAddresses' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts STRING_ARRAY addresses as parameter.
#
import re


def validateAddresses(addresses):
    # Write your code here
    result = []

    IPv4_formatting = '([1-9]?\d|1\d\d|2[0-4]\d|25[0-5])'
    IPv4_pattern = re.compile('^{0}(\.{0}){{3}}$'.format(IPv4_formatting))

    IPv6_formatting = '([0-9a-f]{1,4})'
    IPv6_pattern = re.compile('^({0}::)|(::{0})|({0}::)({0})((:{0}){{0,4}})|({0})((:{0}){{0,4}})(::{0})|({0})((:{0}){{7}})|(({0})((:{0}){{0,3}})(::{0})((:{0}){{0,1}}))|(({0})((:{0}){{0,2}})(::{0})((:{0}){{0,2}}))|(({0})((:{0}){{0,1}})(::{0})((:{0}){{0,3}}))$'.format(IPv6_formatting))
    IPv6_pattern = re.compile("""^({0}::)|
                              (::{0})|
                              (({0}::)({0})((:{0}){{0,4}}))|
                              (({0})((:{0}){{0,4}})(::{0}))|
                              (({0})((:{0}){{7}}))|
                              ( ({0}) ((:{0}){{0,3}}) (::{0}) ((:{0}){{0,1}}))|
                              ( ({0}) ((:{0}){{0,2}}) (::{0}) ((:{0}){{0,2}}))|
                             (({0})((:{0}){{0,1}})(::{0}) ((:{0}){{0,3}}))$""".format(IPv6_formatting))
    for address in addresses:
        if IPv4_pattern.match(address):
            result.append('IPv4')
        elif IPv6_pattern.match(address):
            result.append('IPv6')
        else:
            result.append('Neither')
    return result


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    addresses_count = int(input().strip())

    addresses = []

    for _ in range(addresses_count):
        addresses_item = input()
        addresses.append(addresses_item)

    result = validateAddresses(addresses)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
