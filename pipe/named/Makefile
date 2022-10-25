all: run

start:
	@echo "Starting server..."
	@mkfifo fifo
	@tail -f fifo & echo $$! > .server.pid

stop:
	@echo "Stopping server..."
	@kill `cat .server.pid`
	@rm .server.pid fifo

query:
	echo "write a new line on the named pipe" > fifo

run: | start query stop
