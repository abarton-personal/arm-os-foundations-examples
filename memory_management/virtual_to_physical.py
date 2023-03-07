import sys

pid = int(sys.argv[1], 10) # specify as decimal
vaddr = int(sys.argv[2], 16) # specify as hex

PAGESIZE=4096 # 4K pages
ENTRYSIZE=8

with open(("/proc/%d/pagemap" % pid), "rb") as f:
    f.seek((vaddr/PAGESIZE) * ENTRYSIZE)
    x = 0
    for i in range(ENTRYSIZE):
        x = (ord(f.read(1))<<(8*i)) + x # little endian
        
    # interpret entry
    present = (x>>63) & 1
    swapped = (x>>62) & 1
    file_page = (x>>61) & 1
    soft_dirty =(x>>54) & 1
    paddr = x & ((1<<32)-1)

    print ("virtual address %x maps to **%d%d%d%d** %x" %
            (vaddr, present, swapped, file_page, soft_dirty, (paddr*PAGESIZE)))