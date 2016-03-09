FROM epitechcontent/blinux
MAINTAINER Julien Karst contact@julienkarst.com

VOLUME ["/home/developer/nmobjdump"]
WORKDIR /home/developer/nmobjdump/test
CMD /home/developer/nmobjdump/test/run.sh

# docker run -ti -v ~/psu_2015_nmobjdump/:/home/developer/nmobjdump nmobjdump