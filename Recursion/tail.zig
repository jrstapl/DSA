const std = @import("std");

pub fn fun(n: i32) i32 {
    if (n == 0) {
        return n;
    }

    return fun(n - 1) + n;
}

pub fn main() void {
    const x: i32 = fun(5);
    std.debug.print("{}\n", .{x});
}
