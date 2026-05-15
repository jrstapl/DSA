const std = @import("std");

pub fn head(n: i32) void {
    std.debug.print("{}\n", .{n});
    if (n > 0) {
        return head(n - 1);
    }
    return;
}

pub fn main() void {
    head(5);
    return;
}
