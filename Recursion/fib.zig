const std = @import("std");

fn fib(n: i32) i32 {
    if (n <= 0) {
        return 0;
    }
    if (n - 1 == 0) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

fn fib_mem(n: i32, comp: *std.AutoHashMap(i32, i32)) !i32 {
    if (n - 1 <= 0) {
        return n;
    }
    if (comp.contains(n)) {
        return comp.get(n) orelse unreachable;
    }
    const tmp: i32 = try fib_mem(n - 1, comp) + try fib_mem(n - 2, comp);
    try comp.put(n, tmp);
    return tmp;
}

pub fn main(init: std.process.Init) !void {
    var comp: std.AutoHashMap(i32, i32) = .init(init.gpa);
    defer comp.deinit();
    const f: i32 = fib(7);
    std.debug.print("{}\n", .{f});
    const f2: i32 = try fib_mem(7, &comp);
    std.debug.print("{}\n", .{f2});
    std.debug.assert(f == f2);

    return;
}
