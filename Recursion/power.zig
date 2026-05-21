const std = @import("std");

fn power(i: i64, n: i64) i64 {
    if (n <= 0) {
        return 1;
    }

    return i * power(i, n - 1);
}

fn power_opt(i: i64, n: i64) i64 {
    if (n <= 0) {
        return 1;
    }

    if (@mod(n, 2) == 0) {
        return power_opt(i * i, @divFloor(n, 2));
    } else {
        return i * power_opt(i * i, @divFloor((n - 1), 2));
    }
}

pub fn main(init: std.process.Init) void {
    _ = init;
    const p: i64 = power_opt(2, 2);
    std.debug.print("{}\n", .{p});
    std.debug.assert(power(2, 9) == power_opt(2, 9));
    return;
}
