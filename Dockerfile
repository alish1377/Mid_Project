FROM gcc:10.2.0

WORKDIR /usr/src/app

RUN apt-get -qq update \
    && apt-get -qq install --no-install-recommends cmake \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*


COPY . .

RUN mkdir obj

RUN make

CMD [ "./main" ]