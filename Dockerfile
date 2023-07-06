FROM gcc:13.1.0 as build

WORKDIR /app

RUN useradd -u 1001 nonroot

COPY . /app

RUN make docker

FROM scratch

ENV GIN_MODE release

COPY --from=build /app/generator/generator generator
COPY --from=build /app/solver/solver solver

COPY --from=build /etc/passwd /etc/passwd

USER nonroot

CMD ["/generator"]
