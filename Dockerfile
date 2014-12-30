FROM google/golang
MAINTAINER duguying2008@gmail.com

RUN apt-get install -y gcc
RUN apt-get install -y cmake

ADD . /gopath/src/github.com/duguying/judger

# set the working directory and add current stuff
WORKDIR /gopath/src/github.com/duguying/judger/sandbox/c/build
RUN cmake ..
RUN make

WORKDIR /gopath/src/github.com/duguying/judger
RUN git checkout master
RUN go get
RUN go build
RUN mkdir build

# prepare data and config
RUN mkdir /data
ADD ./sandbox/c/build/executer.json /data/executer.json
ADD ./conf/config_docker.ini /data/config_docker.ini

EXPOSE 1004 1005
ENTRYPOINT []
CMD ["./judger","-c=/data/config_docker.ini"]