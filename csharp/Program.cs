﻿using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using view;
using util;
using model;
using exceptions;

class Program
{
    public static void Main(string[] args)
    {
        CreateHostBuilder(args).Build().Run();
    }

    public static IHostBuilder CreateHostBuilder(string[] args)
    {
        return Host.CreateDefaultBuilder(args).ConfigureServices((hostContext, services) =>
        {
            services.AddHostedService<Castle>();
            services.AddScoped<Princess>();
            services.AddScoped<Hall>();
            services.AddScoped<Friend>(); 
            services.AddScoped<CharacterGenerator>();
            services.AddScoped<ThroneRoom>();
        });
    }
}
