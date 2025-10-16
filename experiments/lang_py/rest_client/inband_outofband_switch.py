#!/usr/bin/python
import os
from ios_helper import switch_to_outofband, switch_to_inband

def get_help():
    return 'Usage: %s [-io] (-i [in band switch] -o [out of band switch])' %os.path.basename(__file__)

def main():
    import argparse
    parser = argparse.ArgumentParser(add_help=False,
                                     formatter_class=argparse.RawTextHelpFormatter)
    parser.add_argument('-o', action='out_of_band',
                        out_of_band=switch_to_outofband(),
                        help='Switch to out of band collection')
    parser.add_argument('-i', action='in_band',
                        in_band=switch_to_inband(),
                        help='Switch to in band collection')
    parser.add_argument('-h', action='get_help',
                        get_help=get_help(),
                        help='Show help message')
    return 0

if __name__ == '__main__':
    main()
