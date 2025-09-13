import gdb

# Register the quit hook
def on_quit(event):
    gdb.execute('kill')

gdb.events.gdb_exiting.connect(on_quit)

# Connect to the remote target
gdb.execute('target remote localhost:1234')

gdb.execute('layout split')
