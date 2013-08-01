#!/usr/bin/env python

import sys
import serial
import select
from optparse import OptionParser

parser = OptionParser(usage="usage: %prog [options] arg1 arg2")
parser.add_option("-v", "--verbose", action="store_true", dest="verbose", default=False, help="verbose on")
parser.add_option("-d", "--device", dest="device", type="string", help="tty to interact with Arduino")
parser.add_option("-p", "--port", dest="port", default=8585, type="int", help="port number to run on")
parser.add_option("-c", "--command", dest="cmd", type="string", help="string to send")

(opts, args) = parser.parse_args()

if __name__ == "__main__":

    # TODO: do options checking

    if opts.device == None:
        print "no device given: try help"
        sys.exit(1)

    if opts.cmd == None:
        print "no command given: try help"
        sys.exit(1)

    print "trying to connect to arduino via %s" % (opts.device)

    try:
        ser = serial.Serial(opts.device, 9600)
        print "sending command: '%s'" % (opts.cmd)
        ser.writeln(opts.cmd)
        while True:
            print ser.readline().strip()
    except:
        pass

